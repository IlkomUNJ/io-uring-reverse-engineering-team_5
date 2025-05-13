// SPDX-License-Identifier: GPL-2.0

#include "cancel.h"

// Prepares a futex operation based on the provided request and submission queue entry.
int io_futex_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Prepares a futex vector operation based on the provided request and submission queue entry.
int io_futexv_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Waits for a futex operation to complete.
int io_futex_wait(struct io_kiocb *req, unsigned int issue_flags);

// Waits for a futex vector operation to complete.
int io_futexv_wait(struct io_kiocb *req, unsigned int issue_flags);

// Wakes up a futex operation based on the request.
int io_futex_wake(struct io_kiocb *req, unsigned int issue_flags);

#if defined(CONFIG_FUTEX)
// Cancels a futex operation and removes it from the cancellation list.
int io_futex_cancel(struct io_ring_ctx *ctx, struct io_cancel_data *cd,
		    unsigned int issue_flags);

// Removes all futex operations associated with a given task context.
bool io_futex_remove_all(struct io_ring_ctx *ctx, struct io_uring_task *tctx,
			 bool cancel_all);

// Initializes the futex cache for the provided ring context.
bool io_futex_cache_init(struct io_ring_ctx *ctx);

// Frees the futex cache resources for the provided ring context.
void io_futex_cache_free(struct io_ring_ctx *ctx);

#else
// If FUTEX is not enabled, inline versions that return default values are provided.
static inline int io_futex_cancel(struct io_ring_ctx *ctx,
				  struct io_cancel_data *cd,
				  unsigned int issue_flags)
{
	return 0;
}

static inline bool io_futex_remove_all(struct io_ring_ctx *ctx,
				       struct io_uring_task *tctx, bool cancel_all)
{
	return false;
}

static inline bool io_futex_cache_init(struct io_ring_ctx *ctx)
{
	return false;
}

static inline void io_futex_cache_free(struct io_ring_ctx *ctx)
{
}
#endif
