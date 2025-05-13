// SPDX-License-Identifier: GPL-2.0

#include <linux/io_uring_types.h>

#define IO_POLL_ALLOC_CACHE_MAX 32

enum {
	IO_APOLL_OK,
	IO_APOLL_ABORTED,
	IO_APOLL_READY
};

/**
 * Holds state for a poll operation, including file, waitqueue, events,
 * retry count, and wait entry.
 */
struct io_poll {
	struct file			*file;
	struct wait_queue_head		*head;
	__poll_t			events;
	int				retries;
	struct wait_queue_entry		wait;
};

/**
 * Holds state for an async poll operation, including main and double poll entries.
 */
struct async_poll {
	struct io_poll		poll;
	struct io_poll		*double_poll;
};

/*
 * Must only be called inside issue_flags & IO_URING_F_MULTISHOT, or
 * potentially other cases where we already "own" this poll request.
 */
/**
 * Increment poll_refs for a multishot poll request to allow retry.
 */
static inline void io_poll_multishot_retry(struct io_kiocb *req)
{
	atomic_inc(&req->poll_refs);
}

/**
 * Prepare a poll add request from an io_uring submission queue entry.
 * Validates and sets up the poll request structure.
 */
int io_poll_add_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Add a poll request to the waitqueue and hash table for event notification.
 */
int io_poll_add(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepare a poll remove request from an io_uring submission queue entry.
 * Validates and sets up the poll removal structure.
 */
int io_poll_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Remove a poll request and optionally update its events or user data.
 */
int io_poll_remove(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Cancel a poll request by user data or file descriptor.
 */
struct io_cancel_data;
int io_poll_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
		   unsigned issue_flags);
/**
 * Arm a poll handler for a request, setting up async polling.
 */
int io_arm_poll_handler(struct io_kiocb *req, unsigned issue_flags);
/**
 * Remove all poll requests for a context, optionally filtering by task.
 */
bool io_poll_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			bool cancel_all);

/**
 * Task work handler for poll requests, processes poll events and completion.
 */
void io_poll_task_func(struct io_kiocb *req, io_tw_token_t tw);
