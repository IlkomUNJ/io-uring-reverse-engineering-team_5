// SPDX-License-Identifier: GPL-2.0

#include <linux/io_uring/cmd.h>
#include <linux/io_uring_types.h>

struct io_async_cmd {
	struct io_uring_cmd_data	data;
	struct iou_vec			vec;
	struct io_uring_sqe		sqes[2];
};

/**
 * Executes a uring command operation for the given request, handling the command logic.
 */
int io_uring_cmd(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepares a uring command request by parsing and validating the SQE fields.
 */
int io_uring_cmd_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Cleans up resources associated with a uring command request.
 */
void io_uring_cmd_cleanup(struct io_kiocb *req);

/**
 * Attempts to cancel one or all uring command requests for a given context and task.
 */
bool io_uring_try_cancel_uring_cmd(struct io_ring_ctx *ctx,
				   struct io_uring_task *tctx, bool cancel_all);

/**
 * Frees a cached uring command entry from memory.
 */
void io_cmd_cache_free(const void *entry);

/**
 * Imports a fixed user-space iovec into a kernel iterator for uring command operations.
 */
int io_uring_cmd_import_fixed_vec(struct io_uring_cmd *ioucmd,
				  const struct iovec __user *uvec,
				  size_t uvec_segs,
				  int ddir, struct iov_iter *iter,
				  unsigned issue_flags);
