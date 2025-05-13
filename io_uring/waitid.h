// SPDX-License-Identifier: GPL-2.0

#include "../kernel/exit.h"

/**
 * Holds async state for a waitid operation, including request pointer and wait options.
 */
struct io_waitid_async {
	struct io_kiocb *req;
	struct wait_opts wo;
};

/**
 * Prepare waitid operation by extracting parameters from the SQE and setting up async data.
 * Sets up the request for asynchronous waitid execution.
 */
int io_waitid_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Execute the waitid operation, add to wait queue, and handle completion or cancellation.
 * Manages asynchronous process waiting and result delivery.
 */
int io_waitid(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Cancel a waitid request matching the cancel data, removing it from the wait queue.
 * Returns 0 on success or a negative error code.
 */
int io_waitid_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
		     unsigned int issue_flags);

/**
 * Remove and cancel all waitid requests associated with a given task context.
 * Returns true if any waitid requests were removed.
 */
bool io_waitid_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			  bool cancel_all);
