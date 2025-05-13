// SPDX-License-Identifier: GPL-2.0

/**
 * Holds state for a timeout operation, including request pointer, timer,
 * timespec, timer mode, and flags.
 */
struct io_timeout_data {
	struct io_kiocb			*req;
	struct hrtimer			timer;
	struct timespec64		ts;
	enum hrtimer_mode		mode;
	u32				flags;
};

/**
 * Disarm a linked timeout and remove it from the list if its timer can be cancelled.
 * Returns the disarmed request or NULL.
 */
struct io_kiocb *__io_disarm_linked_timeout(struct io_kiocb *req,
					    struct io_kiocb *link);

static inline struct io_kiocb *io_disarm_linked_timeout(struct io_kiocb *req)
{
	struct io_kiocb *link = req->link;

	if (link && link->opcode == IORING_OP_LINK_TIMEOUT)
		return __io_disarm_linked_timeout(req, link);

	return NULL;
}

/**
 * Flush all expired or satisfied timeouts in the context.
 */
__cold void io_flush_timeouts(struct io_ring_ctx *ctx);

struct io_cancel_data;

/**
 * Cancel a timeout request matching the cancel data.
 * Returns 0 on success or a negative error code.
 */
int io_timeout_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd);

/**
 * Kill and flush all timeouts associated with a given task context.
 * Returns true if any timeouts were killed.
 */
__cold bool io_kill_timeouts(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			     bool cancel_all);

/**
 * Queue a linked timeout request for execution and start its timer if needed.
 */
void io_queue_linked_timeout(struct io_kiocb *req);

/**
 * Disarm and cancel the next linked timeout request if present.
 */
void io_disarm_next(struct io_kiocb *req);

/**
 * Prepare a timeout request from the SQE.
 */
int io_timeout_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Prepare a linked timeout request from the SQE.
 */
int io_link_timeout_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Issue a timeout request, add it to the context's timeout list, and start the timer.
 */
int io_timeout(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepare a timeout removal or update request from the SQE.
 * Validates input and extracts parameters for removal or update.
 */
int io_timeout_remove_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Remove or update an existing timeout command.
 * Handles both removal and update logic based on flags.
 */
int io_timeout_remove(struct io_kiocb *req, unsigned int issue_flags);
