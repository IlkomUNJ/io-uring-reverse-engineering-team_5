// SPDX-License-Identifier: GPL-2.0
#ifndef IOU_KBUF_H
#define IOU_KBUF_H

#include <uapi/linux/io_uring.h>
#include <linux/io_uring_types.h>

enum {
	/* ring mapped provided buffers */
	IOBL_BUF_RING	= 1,
	/* buffers are consumed incrementally rather than always fully */
	IOBL_INC	= 2,
};

/**
 * Buffer list structure for managing provided and ring-mapped buffers in io_uring.
 */
struct io_buffer_list {
	/*
	 * If ->buf_nr_pages is set, then buf_pages/buf_ring are used. If not,
	 * then these are classic provided buffers and ->buf_list is used.
	 */
	union {
		struct list_head buf_list;
		struct io_uring_buf_ring *buf_ring;
	};
	__u16 bgid;

	/* below is for ring provided buffers */
	__u16 buf_nr_pages;
	__u16 nr_entries;
	__u16 head;
	__u16 mask;

	__u16 flags;

	struct io_mapped_region region;
};

/**
 * Buffer structure representing a single user-provided buffer.
 */
struct io_buffer {
	struct list_head list;
	__u64 addr;
	__u32 len;
	__u16 bid;
	__u16 bgid;
};

enum {
	/* can alloc a bigger vec */
	KBUF_MODE_EXPAND	= 1,
	/* if bigger vec allocated, free old one */
	KBUF_MODE_FREE		= 2,
};

/**
 * Arguments for buffer selection, including iovec array and limits.
 */
struct buf_sel_arg {
	struct iovec *iovs;
	size_t out_len;
	size_t max_len;
	unsigned short nr_iovs;
	unsigned short mode;
};

/**
 * Select a buffer for a request, handling both mapped ring and legacy lists.
 */
void __user *io_buffer_select(struct io_kiocb *req, size_t *len,
			      unsigned int issue_flags);

/**
 * Select and commit buffers for a request, supporting both ring and legacy lists.
 */
int io_buffers_select(struct io_kiocb *req, struct buf_sel_arg *arg,
		      unsigned int issue_flags);

/**
 * Peek available buffers for a request, filling iovecs without committing.
 */
int io_buffers_peek(struct io_kiocb *req, struct buf_sel_arg *arg);

/**
 * Destroy all buffer lists and free their resources in the context.
 */
void io_destroy_buffers(struct io_ring_ctx *ctx);

/**
 * Prepare a request to remove buffers, validating SQE fields and filling struct.
 */
int io_remove_buffers_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Remove buffers from a buffer list for a request, updating state and result.
 */
int io_remove_buffers(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepare a request to provide buffers, validating SQE fields and filling struct.
 */
int io_provide_buffers_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Provide buffers for a request, adding them to the buffer list and updating state.
 */
int io_provide_buffers(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Register a new mapped buffer ring for a buffer group in the context.
 */
int io_register_pbuf_ring(struct io_ring_ctx *ctx, void __user *arg);

/**
 * Unregister and free a mapped buffer ring for a buffer group in the context.
 */
int io_unregister_pbuf_ring(struct io_ring_ctx *ctx, void __user *arg);

/**
 * Get the status of a mapped buffer ring for a buffer group.
 */
int io_register_pbuf_status(struct io_ring_ctx *ctx, void __user *arg);

/**
 * Recycle a legacy buffer back to its buffer list for reuse.
 */
bool io_kbuf_recycle_legacy(struct io_kiocb *req, unsigned issue_flags);

/**
 * Drop and free a legacy selected buffer from a request.
 */
void io_kbuf_drop_legacy(struct io_kiocb *req);

/**
 * Finalize buffer usage for a request, handling both ring and legacy buffers.
 */
unsigned int __io_put_kbufs(struct io_kiocb *req, int len, int nbufs);

/**
 * Commit buffer usage for a request, updating buffer list state as needed.
 */
bool io_kbuf_commit(struct io_kiocb *req,
		    struct io_buffer_list *bl, int len, int nr);

/**
 * Get the mapped region for a buffer group if it is a mapped buffer ring.
 */
struct io_mapped_region *io_pbuf_get_region(struct io_ring_ctx *ctx,
					    unsigned int bgid);

/**
 * Recycle a buffer from a ring-mapped buffer list for reuse.
 */
static inline bool io_kbuf_recycle_ring(struct io_kiocb *req)
{
	/*
	 * We don't need to recycle for REQ_F_BUFFER_RING, we can just clear
	 * the flag and hence ensure that bl->head doesn't get incremented.
	 * If the tail has already been incremented, hang on to it.
	 * The exception is partial io, that case we should increment bl->head
	 * to monopolize the buffer.
	 */
	if (req->buf_list) {
		req->buf_index = req->buf_list->bgid;
		req->flags &= ~(REQ_F_BUFFER_RING|REQ_F_BUFFERS_COMMIT);
		return true;
	}
	return false;
}

/**
 * Check if buffer selection is needed for the request.
 */
static inline bool io_do_buffer_select(struct io_kiocb *req)
{
	if (!(req->flags & REQ_F_BUFFER_SELECT))
		return false;
	return !(req->flags & (REQ_F_BUFFER_SELECTED|REQ_F_BUFFER_RING));
}

/**
 * Recycle a buffer for a request, handling both legacy and ring-mapped buffers.
 */
static inline bool io_kbuf_recycle(struct io_kiocb *req, unsigned issue_flags)
{
	if (req->flags & REQ_F_BL_NO_RECYCLE)
		return false;
	if (req->flags & REQ_F_BUFFER_SELECTED)
		return io_kbuf_recycle_legacy(req, issue_flags);
	if (req->flags & REQ_F_BUFFER_RING)
		return io_kbuf_recycle_ring(req);
	return false;
}

/**
 * Finalize and return a single buffer for a request.
 */
static inline unsigned int io_put_kbuf(struct io_kiocb *req, int len,
				       unsigned issue_flags)
{
	if (!(req->flags & (REQ_F_BUFFER_RING | REQ_F_BUFFER_SELECTED)))
		return 0;
	return __io_put_kbufs(req, len, 1);
}

/**
 * Finalize and return multiple buffers for a request.
 */
static inline unsigned int io_put_kbufs(struct io_kiocb *req, int len,
					int nbufs, unsigned issue_flags)
{
	if (!(req->flags & (REQ_F_BUFFER_RING | REQ_F_BUFFER_SELECTED)))
		return 0;
	return __io_put_kbufs(req, len, nbufs);
}
#endif
