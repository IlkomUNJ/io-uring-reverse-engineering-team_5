// SPDX-License-Identifier: GPL-2.0

struct io_tctx_node {
	struct list_head	ctx_node;
	struct task_struct	*task;
	struct io_ring_ctx	*ctx;
};

/**
 * Allocate and initialize an io_uring_task context for the given task and ring context.
 * Sets up workqueue, counters, waitqueue, and links the context to the task.
 */
int io_uring_alloc_task_context(struct task_struct *task,
				struct io_ring_ctx *ctx);

/**
 * Remove the mapping between an io_uring file and a task for the given index.
 * Cleans up and unlinks the tctx node from the context and task.
 */
void io_uring_del_tctx_node(unsigned long index);

/**
 * Add a tctx (task context) node for the current task to the given ring context.
 * Allocates and links the node if not already present, and sets worker limits if needed.
 */
int __io_uring_add_tctx_node(struct io_ring_ctx *ctx);

/**
 * Add a tctx node from a submit context, handling single issuer logic.
 * Ensures the current task is registered and updates the last context pointer.
 */
int __io_uring_add_tctx_node_from_submit(struct io_ring_ctx *ctx);

/**
 * Clean up all tctx nodes and workqueue for the given io_uring_task.
 * Iterates and removes all context nodes, then releases the workqueue.
 */
void io_uring_clean_tctx(struct io_uring_task *tctx);

/**
 * Unregister all ring file descriptors associated with the current task.
 * Releases and clears all registered ring file pointers.
 */
void io_uring_unreg_ringfd(void);

/**
 * Register ring file descriptors for the given context from user arguments.
 * Handles user array input, finds available slots, and updates user memory.
 */
int io_ringfd_register(struct io_ring_ctx *ctx, void __user *__arg,
		       unsigned nr_args);

/**
 * Unregister ring file descriptors for the given context from user arguments.
 * Releases and clears the specified registered ring file pointers.
 */
int io_ringfd_unregister(struct io_ring_ctx *ctx, void __user *__arg,
			 unsigned nr_args);

/*
 * Note that this task has used io_uring. We use it for cancelation purposes.
 */
static inline int io_uring_add_tctx_node(struct io_ring_ctx *ctx)
{
	struct io_uring_task *tctx = current->io_uring;

	if (likely(tctx && tctx->last == ctx))
		return 0;

	return __io_uring_add_tctx_node_from_submit(ctx);
}
