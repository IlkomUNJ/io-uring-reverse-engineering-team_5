// SPDX-License-Identifier: GPL-2.0
#ifndef IORING_CANCEL_H
#define IORING_CANCEL_H

#include <linux/io_uring_types.h>

/**
 * Holds information required to identify and cancel an asynchronous io_uring request.
 * Includes context, data/file, opcode, flags, and sequence number for matching.
 */
struct io_cancel_data {
	struct io_ring_ctx *ctx;
	union {
		u64 data;
		struct file *file;
	};
	u8 opcode;
	u32 flags;
	int seq;
};

// Prepares the cancellation of an asynchronous request.
int io_async_cancel_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Cancels an asynchronous request.
int io_async_cancel(struct io_kiocb *req, unsigned int issue_flags);

// Attempts to cancel a request.
int io_try_cancel(struct io_uring_task *tctx, struct io_cancel_data *cd,
		  unsigned int issue_flags);

// Cancels a synchronous request based on user input.
int io_sync_cancel(struct io_ring_ctx *ctx, void __user *arg);

// Checks if a request matches the cancel data.
bool io_cancel_req_match(struct io_kiocb *req, struct io_cancel_data *cd);

// Removes and cancels requests from the list.
bool io_cancel_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			  struct hlist_head *list, bool cancel_all,
			  bool (*cancel)(struct io_kiocb *));

// Removes and cancels a specific request from the list.
int io_cancel_remove(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
		     unsigned int issue_flags, struct hlist_head *list,
		     bool (*cancel)(struct io_kiocb *));

// Checks if the request matches the given cancellation sequence.
static inline bool io_cancel_match_sequence(struct io_kiocb *req, int sequence)
{
	if (req->cancel_seq_set && sequence == req->work.cancel_seq)
		return true;

	req->cancel_seq_set = true;
	req->work.cancel_seq = sequence;
	return false;
}

#endif
