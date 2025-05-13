// SPDX-License-Identifier: GPL-2.0

/**
 * Holds state for the SQPOLL offload thread, including references, thread info,
 * waitqueue, CPU affinity, and context list.
 */
struct io_sq_data {
	refcount_t		refs;
	atomic_t		park_pending;
	struct mutex		lock;

	/* ctx's that are using this sqd */
	struct list_head	ctx_list;

	struct task_struct	*thread;
	struct wait_queue_head	wait;

	unsigned		sq_thread_idle;
	int			sq_cpu;
	pid_t			task_pid;
	pid_t			task_tgid;

	u64			work_time;
	unsigned long		state;
	struct completion	exited;
};

/**
 * Creates and initializes the SQPOLL thread if requested in the parameters.
 * Handles attaching to an existing SQPOLL or spawning a new one.
 */
int io_sq_offload_create(struct io_ring_ctx *ctx, struct io_uring_params *p);

/**
 * Finalizes and cleans up the SQPOLL context, including detachment.
 */
void io_sq_thread_finish(struct io_ring_ctx *ctx);

/**
 * Signals the SQPOLL thread to stop and waits for its completion.
 */
void io_sq_thread_stop(struct io_sq_data *sqd);

/**
 * Temporarily disables the SQPOLL thread's operation (parks it).
 * Must be followed by a corresponding unpark.
 */
void io_sq_thread_park(struct io_sq_data *sqd);

/**
 * Resumes operation of a previously parked SQPOLL thread.
 */
void io_sq_thread_unpark(struct io_sq_data *sqd);

/**
 * Decrements the reference count and frees sqd if no longer in use.
 */
void io_put_sq_data(struct io_sq_data *sqd);

/**
 * Waits for space in the SQ ring if it is currently full.
 * Blocks the caller until space becomes available or interrupted.
 */
void io_sqpoll_wait_sq(struct io_ring_ctx *ctx);

/**
 * Sets CPU affinity for the SQPOLL thread to the provided mask.
 * Returns 0 on success, -EINVAL on error or if no SQPOLL active.
 */
int io_sqpoll_wq_cpu_affinity(struct io_ring_ctx *ctx, cpumask_var_t mask);
