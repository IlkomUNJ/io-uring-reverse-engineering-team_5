// SPDX-License-Identifier: GPL-2.0
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/fdtable.h>
#include <linux/fsnotify.h>
#include <linux/namei.h>
#include <linux/io_uring.h>

#include <uapi/linux/io_uring.h>

#include "../fs/internal.h"
#include "io_uring.h"
#include "rsrc.h"
#include "openclose.h"

/**
 * Holds state for an open operation, including file, directory fd, filename,
 * open flags, and resource limits.
 */
struct io_open {
	struct file			*file;
	int				dfd;
	u32				file_slot;
	struct filename			*filename;
	struct open_how			how;
	unsigned long			nofile;
};

/**
 * Holds state for a close operation, including file and file descriptor info.
 */
struct io_close {
	struct file			*file;
	int				fd;
	u32				file_slot;
};

/**
 * Holds state for installing a file into the fixed file table.
 */
struct io_fixed_install {
	struct file			*file;
	unsigned int			o_flags;
};

/*
 * io_openat_force_async() - Determines if open should be forced async based on flags.
 */
static bool io_openat_force_async(struct io_open *open)
{
	return open->how.flags & (O_TRUNC | O_CREAT | __O_TMPFILE);
}

/*
 * __io_openat_prep() - Prepares open request by extracting fields and checking constraints.
 */
static int __io_openat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe)
{
	struct io_open *open = io_kiocb_to_cmd(req, struct io_open);
	const char __user *fname;
	int ret;

	if (unlikely(sqe->buf_index))
		return -EINVAL;
	if (unlikely(req->flags & REQ_F_FIXED_FILE))
		return -EBADF;

	if (!(open->how.flags & O_PATH) && force_o_largefile())
		open->how.flags |= O_LARGEFILE;

	open->dfd = READ_ONCE(sqe->fd);
	fname = u64_to_user_ptr(READ_ONCE(sqe->addr));
	open->filename = getname(fname);
	if (IS_ERR(open->filename)) {
		ret = PTR_ERR(open->filename);
		open->filename = NULL;
		return ret;
	}

	open->file_slot = READ_ONCE(sqe->file_index);
	if (open->file_slot && (open->how.flags & O_CLOEXEC))
		return -EINVAL;

	open->nofile = rlimit(RLIMIT_NOFILE);
	req->flags |= REQ_F_NEED_CLEANUP;
	if (io_openat_force_async(open))
		req->flags |= REQ_F_FORCE_ASYNC;
	return 0;
}

/*
 * io_openat_prep() - Parses and prepares openat request from sqe.
 */
int io_openat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe)
{
	struct io_open *open = io_kiocb_to_cmd(req, struct io_open);
	u64 mode = READ_ONCE(sqe->len);
	u64 flags = READ_ONCE(sqe->open_flags);

	open->how = build_open_how(flags, mode);
	return __io_openat_prep(req, sqe);
}

/*
 * io_openat2_prep() - Prepares openat2 request using user-provided open_how structure.
 */
int io_openat2_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe)
{
	struct io_open *open = io_kiocb_to_cmd(req, struct io_open);
	struct open_how __user *how;
	size_t len;
	int ret;

	how = u64_to_user_ptr(READ_ONCE(sqe->addr2));
	len = READ_ONCE(sqe->len);
	if (len < OPEN_HOW_SIZE_VER0)
		return -EINVAL;

	ret = copy_struct_from_user(&open->how, sizeof(open->how), how, len);
	if (ret)
		return ret;

	return __io_openat_prep(req, sqe);
}

/*
 * io_openat2() - Handles openat2 operation, including file allocation and installation.
 */
int io_openat2(struct io_kiocb *req, unsigned int issue_flags)
{
	struct io_open *open = io_kiocb_to_cmd(req, struct io_open);
	struct open_flags op;
	struct file *file;
	bool resolve_nonblock, nonblock_set;
	bool fixed = !!open->file_slot;
	int ret;

	ret = build_open_flags(&open->how, &op);
	if (ret)
		goto err;
	nonblock_set = op.open_flag & O_NONBLOCK;
	resolve_nonblock = open->how.resolve & RESOLVE_CACHED;
	if (issue_flags & IO_URING_F_NONBLOCK) {
		WARN_ON_ONCE(io_openat_force_async(open));
		op.lookup_flags |= LOOKUP_CACHED;
		op.open_flag |= O_NONBLOCK;
	}

	if (!fixed) {
		ret = __get_unused_fd_flags(open->how.flags, open->nofile);
		if (ret < 0)
			goto err;
	}

	file = do_filp_open(open->dfd, open->filename, &op);
	if (IS_ERR(file)) {
		if (!fixed)
			put_unused_fd(ret);

		ret = PTR_ERR(file);
		if (ret == -EAGAIN &&
		    (!resolve_nonblock && (issue_flags & IO_URING_F_NONBLOCK)))
			return -EAGAIN;
		goto err;
	}

	if ((issue_flags & IO_URING_F_NONBLOCK) && !nonblock_set)
		file->f_flags &= ~O_NONBLOCK;

	if (!fixed)
		fd_install(ret, file);
	else
		ret = io_fixed_fd_install(req, issue_flags, file,
						open->file_slot);
err:
	putname(open->filename);
	req->flags &= ~REQ_F_NEED_CLEANUP;
	if (ret < 0)
		req_set_fail(req);
	io_req_set_res(req, ret, 0);
	return IOU_OK;
}

/*
 * io_openat() - Wrapper for io_openat2().
 */
int io_openat(struct io_kiocb *req, unsigned int issue_flags)
{
	return io_openat2(req, issue_flags);
}

/*
 * io_open_cleanup() - Cleans up allocated resources in open request.
 */
void io_open_cleanup(struct io_kiocb *req)
{
	struct io_open *open = io_kiocb_to_cmd(req, struct io_open);

	if (open->filename)
		putname(open->filename);
}

/*
 * __io_close_fixed() - Closes a fixed file descriptor from the fixed table.
 */
int __io_close_fixed(struct io_ring_ctx *ctx, unsigned int issue_flags,
		     unsigned int offset)
{
	int ret;

	io_ring_submit_lock(ctx, issue_flags);
	ret = io_fixed_fd_remove(ctx, offset);
	io_ring_submit_unlock(ctx, issue_flags);

	return ret;
}

/*
 * io_close_fixed() - Helper to close a fixed file descriptor.
 */
static inline int io_close_fixed(struct io_kiocb *req, unsigned int issue_flags)
{
	struct io_close *close = io_kiocb_to_cmd(req, struct io_close);

	return __io_close_fixed(req->ctx, issue_flags, close->file_slot - 1);
}

/*
 * io_close_prep() - Prepares close request by validating sqe fields.
 */
int io_close_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe)
{
	struct io_close *close = io_kiocb_to_cmd(req, struct io_close);

	if (sqe->off || sqe->addr || sqe->len || sqe->rw_flags || sqe->buf_index)
		return -EINVAL;
	if (req->flags & REQ_F_FIXED_FILE)
		return -EBADF;

	close->fd = READ_ONCE(sqe->fd);
	close->file_slot = READ_ONCE(sqe->file_index);
	if (close->file_slot && close->fd)
		return -EINVAL;

	return 0;
}

/*
 * io_close() - Performs close operation, either normal or fixed.
 */
int io_close(struct io_kiocb *req, unsigned int issue_flags)
{
	struct files_struct *files = current->files;
	struct io_close *close = io_kiocb_to_cmd(req, struct io_close);
	struct file *file;
	int ret = -EBADF;

	if (close->file_slot) {
		ret = io_close_fixed(req, issue_flags);
		goto err;
	}

	spin_lock(&files->file_lock);
	file = files_lookup_fd_locked(files, close->fd);
	if (!file || io_is_uring_fops(file)) {
		spin_unlock(&files->file_lock);
		goto err;
	}

	if (file->f_op->flush && (issue_flags & IO_URING_F_NONBLOCK)) {
		spin_unlock(&files->file_lock);
		return -EAGAIN;
	}

	file = file_close_fd_locked(files, close->fd);
	spin_unlock(&files->file_lock);
	if (!file)
		goto err;

	ret = filp_close(file, current->files);
err:
	if (ret < 0)
		req_set_fail(req);
	io_req_set_res(req, ret, 0);
	return IOU_OK;
}

/*
 * io_install_fixed_fd_prep() - Prepares the installation of a fixed file descriptor.
 */
int io_install_fixed_fd_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe)
{
	struct io_fixed_install *ifi;
	unsigned int flags;

	if (sqe->off || sqe->addr || sqe->len || sqe->buf_index ||
	    sqe->splice_fd_in || sqe->addr3)
		return -EINVAL;

	if (!(req->flags & REQ_F_FIXED_FILE))
		return -EBADF;

	flags = READ_ONCE(sqe->install_fd_flags);
	if (flags & ~IORING_FIXED_FD_NO_CLOEXEC)
		return -EINVAL;

	if (req->flags & REQ_F_CREDS)
		return -EPERM;

	ifi = io_kiocb_to_cmd(req, struct io_fixed_install);
	ifi->o_flags = O_CLOEXEC;
	if (flags & IORING_FIXED_FD_NO_CLOEXEC)
		ifi->o_flags = 0;

	return 0;
}

/*
 * io_install_fixed_fd() - Installs a file descriptor into the fixed table.
*/
int io_install_fixed_fd(struct io_kiocb *req, unsigned int issue_flags)
{
	struct io_fixed_install *ifi;
	int ret;

	ifi = io_kiocb_to_cmd(req, struct io_fixed_install);
	ret = receive_fd(req->file, NULL, ifi->o_flags);
	if (ret < 0)
		req_set_fail(req);
	io_req_set_res(req, ret, 0);
	return IOU_OK;
}
