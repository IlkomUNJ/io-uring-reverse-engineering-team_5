// SPDX-License-Identifier: GPL-2.0
#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/file.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/namei.h>
#include <linux/io_uring.h>

#include <uapi/linux/fadvise.h>
#include <uapi/linux/io_uring.h>

#include "io_uring.h"
#include "advise.h"

/* Structure for file advice operation parameters */
struct io_fadvise {
    struct file     *file;    /* Target file */
    u64             offset;   /* Starting offset */
    u64             len;      /* Length of range */
    u32             advice;   /* Advice type */
};

/* Structure for memory advice operation parameters */
struct io_madvise {
    struct file     *file;    /* Associated file */
    u64             addr;     /* Starting address */
    u64             len;      /* Length of range */
    u32             advice;   /* Advice type */
};

/*
 * Prepares an madvise request for io_uring.
 * Validates and initializes parameters from the submission queue entry.
 * Only available when CONFIG_ADVISE_SYSCALLS and CONFIG_MMU are enabled.
 */
int io_madvise_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe)
{
#if defined(CONFIG_ADVISE_SYSCALLS) && defined(CONFIG_MMU)
    struct io_madvise *ma = io_kiocb_to_cmd(req, struct io_madvise);

    if (sqe->buf_index || sqe->splice_fd_in)
        return -EINVAL;

    ma->addr = READ_ONCE(sqe->addr);
    ma->len = READ_ONCE(sqe->off);
    if (!ma->len)
        ma->len = READ_ONCE(sqe->len);
    ma->advice = READ_ONCE(sqe->fadvise_advice);
    req->flags |= REQ_F_FORCE_ASYNC;
    return 0;
#else
    return -EOPNOTSUPP;
#endif
}

/*
 * Executes the madvise operation asynchronously.
 * Provides memory usage hints to the kernel for optimization.
 * Must not be called in non-blocking context.
 */
int io_madvise(struct io_kiocb *req, unsigned int issue_flags)
{
#if defined(CONFIG_ADVISE_SYSCALLS) && defined(CONFIG_MMU)
    struct io_madvise *ma = io_kiocb_to_cmd(req, struct io_madvise);
    int ret;

    WARN_ON_ONCE(issue_flags & IO_URING_F_NONBLOCK);

    ret = do_madvise(current->mm, ma->addr, ma->len, ma->advice);
    io_req_set_res(req, ret, 0);
    return IOU_OK;
#else
    return -EOPNOTSUPP;
#endif
}

/*
 * Determines if an fadvise operation should be forced to run asynchronously.
 * Normal, random, and sequential access patterns can run synchronously.
 */
static bool io_fadvise_force_async(struct io_fadvise *fa)
{
    switch (fa->advice) {
    case POSIX_FADV_NORMAL:
    case POSIX_FADV_RANDOM:
    case POSIX_FADV_SEQUENTIAL:
        return false;
    default:
        return true;
    }
}

/*
 * Prepares an fadvise request for io_uring.
 * Initializes operation parameters from the submission queue entry.
 */
int io_fadvise_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe)
{
    struct io_fadvise *fa = io_kiocb_to_cmd(req, struct io_fadvise);

    if (sqe->buf_index || sqe->splice_fd_in)
        return -EINVAL;

    fa->offset = READ_ONCE(sqe->off);
    fa->len = READ_ONCE(sqe->addr);
    if (!fa->len)
        fa->len = READ_ONCE(sqe->len);
    fa->advice = READ_ONCE(sqe->fadvise_advice);
    if (io_fadvise_force_async(fa))
        req->flags |= REQ_F_FORCE_ASYNC;
    return 0;
}

/*
 * Executes the fadvise operation asynchronously.
 * Provides file access pattern hints to the filesystem for optimization.
 * Certain advice types may complete synchronously for better performance.
 */
int io_fadvise(struct io_kiocb *req, unsigned int issue_flags)
{
    struct io_fadvise *fa = io_kiocb_to_cmd(req, struct io_fadvise);
    int ret;

    WARN_ON_ONCE(issue_flags & IO_URING_F_NONBLOCK && io_fadvise_force_async(fa));

    ret = vfs_fadvise(req->file, fa->offset, fa->len, fa->advice);
    if (ret < 0)
        req_set_fail(req);
    io_req_set_res(req, ret, 0);
    return IOU_OK;
}