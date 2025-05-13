#ifndef INTERNAL_IO_WQ_H
#define INTERNAL_IO_WQ_H

#include <linux/refcount.h>
#include <linux/io_uring_types.h>

/**
 * Represents the io_wq instance for managing async workers.
 */
struct io_wq;

/**
 * Flags for io_wq_work state and behavior (cancel, hashed, unbound, etc).
 */
enum {
	IO_WQ_WORK_CANCEL	= 1,
	IO_WQ_WORK_HASHED	= 2,
	IO_WQ_WORK_UNBOUND	= 4,
	IO_WQ_WORK_CONCURRENT	= 16,

	IO_WQ_HASH_SHIFT	= 24,	/* upper 8 bits are used for hash key */
};

/**
 * Result codes for io_wq_cancel_cb, indicating cancel status.
 */
enum io_wq_cancel {
	IO_WQ_CANCEL_OK,	/* cancelled before started */
	IO_WQ_CANCEL_RUNNING,	/* found, running, and attempted cancelled */
	IO_WQ_CANCEL_NOTFOUND,	/* work not found */
};

/**
 * Function pointer type for freeing a work item after completion.
 */
typedef struct io_wq_work *(free_work_fn)(struct io_wq_work *);

/**
 * Function pointer type for processing a work item.
 */
typedef void (io_wq_work_fn)(struct io_wq_work *);

/**
 * Hash table for serializing work items by key, with refcount and wait queue.
 */
struct io_wq_hash {
	refcount_t refs;
	unsigned long map;
	struct wait_queue_head wait;
};

/**
 * Decrement hash refcount and free if zero.
 */
static inline void io_wq_put_hash(struct io_wq_hash *hash)
{
	if (refcount_dec_and_test(&hash->refs))
		kfree(hash);
}

/**
 * Data needed to initialize a new io_wq instance.
 */
struct io_wq_data {
	struct io_wq_hash *hash;
	struct task_struct *task;
	io_wq_work_fn *do_work;
	free_work_fn *free_work;
};

/**
 * Create a new io_wq instance with the given configuration.
 */
struct io_wq *io_wq_create(unsigned bounded, struct io_wq_data *data);

/**
 * Begin io_wq shutdown, signaling all workers to exit.
 */
void io_wq_exit_start(struct io_wq *wq);

/**
 * Release all resources and destroy the io_wq instance.
 */
void io_wq_put_and_exit(struct io_wq *wq);

/**
 * Enqueue a work item to the io_wq for asynchronous processing.
 */
void io_wq_enqueue(struct io_wq *wq, struct io_wq_work *work);

/**
 * Mark a work item as hashed for serialization by a specific key.
 */
void io_wq_hash_work(struct io_wq_work *work, void *val);

/**
 * Set or get the CPU affinity mask for io_wq workers.
 */
int io_wq_cpu_affinity(struct io_uring_task *tctx, cpumask_var_t mask);

/**
 * Set or get the maximum number of workers for each accounting group.
 */
int io_wq_max_workers(struct io_wq *wq, int *new_count);

/**
 * Returns true if the current worker should stop (e.g., io-wq is exiting).
 */
bool io_wq_worker_stopped(void);

/**
 * Returns true if the work_flags indicate the work is hashed.
 */
static inline bool __io_wq_is_hashed(unsigned int work_flags)
{
	return work_flags & IO_WQ_WORK_HASHED;
}

/**
 * Returns true if the given work item is hashed.
 */
static inline bool io_wq_is_hashed(struct io_wq_work *work)
{
	return __io_wq_is_hashed(atomic_read(&work->flags));
}

/**
 * Function pointer type for matching and cancelling work items.
 */
typedef bool (work_cancel_fn)(struct io_wq_work *, void *);

/**
 * Attempt to cancel a work item in the io_wq, using a custom match function.
 */
enum io_wq_cancel io_wq_cancel_cb(struct io_wq *wq, work_cancel_fn *cancel,
					void *data, bool cancel_all);

#if defined(CONFIG_IO_WQ)
/**
 * Notify io_wq that a worker is going to sleep, possibly waking or creating others.
 */
extern void io_wq_worker_sleeping(struct task_struct *);

/**
 * Notify io_wq that a worker is running, updating accounting.
 */
extern void io_wq_worker_running(struct task_struct *);
#else
static inline void io_wq_worker_sleeping(struct task_struct *tsk)
{
}
static inline void io_wq_worker_running(struct task_struct *tsk)
{
}
#endif

/**
 * Returns true if the current task is an io_wq worker.
 */
static inline bool io_wq_current_is_worker(void)
{
	return in_task() && (current->flags & PF_IO_WORKER) &&
		current->worker_private;
}
#endif
