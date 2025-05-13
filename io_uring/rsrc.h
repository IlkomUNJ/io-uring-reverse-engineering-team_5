// SPDX-License-Identifier: GPL-2.0
#ifndef IOU_RSRC_H
#define IOU_RSRC_H

#include <linux/io_uring_types.h>
#include <linux/lockdep.h>

#define IO_VEC_CACHE_SOFT_CAP		256

enum {
	IORING_RSRC_FILE		= 0,
	IORING_RSRC_BUFFER		= 1,
};

struct io_rsrc_node {
	unsigned char			type;
	int				refs;

	u64 tag;
	union {
		unsigned long file_ptr;
		struct io_mapped_ubuf *buf;
	};
};

enum {
	IO_IMU_DEST	= 1 << ITER_DEST,
	IO_IMU_SOURCE	= 1 << ITER_SOURCE,
};

/**
 * Holds state for a mapped user or kernel buffer, including address, length,
 * bvec array, reference count, and metadata for buffer management.
 */
struct io_mapped_ubuf {
	u64		ubuf;
	unsigned int	len;
	unsigned int	nr_bvecs;
	unsigned int    folio_shift;
	refcount_t	refs;
	unsigned long	acct_pages;
	void		(*release)(void *);
	void		*priv;
	bool		is_kbuf;
	u8		dir;
	struct bio_vec	bvec[] __counted_by(nr_bvecs);
};

/**
 * Holds metadata for folio layout in a mapped buffer, used for coalescing and validation.
 */
struct io_imu_folio_data {
	/* Head folio can be partially included in the fixed buf */
	unsigned int	nr_pages_head;
	/* For non-head/tail folios, has to be fully included */
	unsigned int	nr_pages_mid;
	unsigned int	folio_shift;
	unsigned int	nr_folios;
};

bool io_rsrc_cache_init(struct io_ring_ctx *ctx);
void io_rsrc_cache_free(struct io_ring_ctx *ctx);
struct io_rsrc_node *io_rsrc_node_alloc(struct io_ring_ctx *ctx, int type);
void io_free_rsrc_node(struct io_ring_ctx *ctx, struct io_rsrc_node *node);
void io_rsrc_data_free(struct io_ring_ctx *ctx, struct io_rsrc_data *data);

/**
 * Allocate an array of io_rsrc_node pointers for resource management.
 * Returns 0 on success or -ENOMEM on failure.
 */
int io_rsrc_data_alloc(struct io_rsrc_data *data, unsigned nr);

/**
 * Find the buffer resource node for a given request and issue flags.
 * Returns the resource node or NULL if not found.
 */
struct io_rsrc_node *io_find_buf_node(struct io_kiocb *req,
				      unsigned issue_flags);
/**
 * Import a registered buffer into an iov_iter for IO operations.
 * Validates and prepares the buffer for use.
 */
int io_import_reg_buf(struct io_kiocb *req, struct iov_iter *iter,
			u64 buf_addr, size_t len, int ddir,
			unsigned issue_flags);
/**
 * Import a vector of registered buffers into a bio_vec iterator for IO.
 * Handles both user and kernel buffers, reallocating if needed.
 */
int io_import_reg_vec(int ddir, struct iov_iter *iter,
			struct io_kiocb *req, struct iou_vec *vec,
			unsigned nr_iovs, unsigned issue_flags);
/**
 * Prepare an iou_vec structure from user-provided iovec array.
 * Allocates or resizes the array and copies data from userspace.
 */
int io_prep_reg_iovec(struct io_kiocb *req, struct iou_vec *iv,
			const struct iovec __user *uvec, size_t uvec_segs);

/**
 * Clone registered buffers from another io_uring context into this context.
 * Used for fast buffer sharing between rings.
 */
int io_register_clone_buffers(struct io_ring_ctx *ctx, void __user *arg);
/**
 * Unregister all registered buffers from the context.
 */
int io_sqe_buffers_unregister(struct io_ring_ctx *ctx);
/**
 * Register user-provided buffers into the SQE buffer table.
 * Copies and validates user-space iovecs and optional tags, then registers them for use with SQEs.
 * Returns 0 on success or a negative error code.
 */
int io_sqe_buffers_register(struct io_ring_ctx *ctx, void __user *arg,
			    unsigned int nr_args, u64 __user *tags);
/**
 * Unregister all registered files from the context.
 */
int io_sqe_files_unregister(struct io_ring_ctx *ctx);
/**
 * Register files for fixed file support in io_uring, storing them in the context.
 */
int io_sqe_files_register(struct io_ring_ctx *ctx, void __user *arg,
			  unsigned nr_args, u64 __user *tags);

/**
 * Update registered files in the context from userspace arguments.
 * Returns number of updated entries or error code.
 */
int io_register_files_update(struct io_ring_ctx *ctx, void __user *arg,
			     unsigned nr_args);
/**
 * Update registered resources (files or buffers) in the context from userspace arguments.
 */
int io_register_rsrc_update(struct io_ring_ctx *ctx, void __user *arg,
			    unsigned size, unsigned type);
/**
 * Register new resources (files or buffers) in the context from userspace arguments.
 */
int io_register_rsrc(struct io_ring_ctx *ctx, void __user *arg,
			unsigned int size, unsigned int type);
/**
 * Validate a user-provided iovec for buffer registration.
 * Checks for valid base, length, and reasonable size.
 */
int io_buffer_validate(struct iovec *iov);

/**
 * Check if a page array can be coalesced into contiguous folios.
 * Verifies page continuity and updates folio metadata.
 */
bool io_check_coalesce_buffer(struct page **page_array, int nr_pages,
			      struct io_imu_folio_data *data);

/**
 * Look up a resource node by index in the resource data array.
 * Returns the node if found, or NULL if out of bounds.
 */
static inline struct io_rsrc_node *io_rsrc_node_lookup(struct io_rsrc_data *data,
						       int index)
{
	if (index < data->nr)
		return data->nodes[array_index_nospec(index, data->nr)];
	return NULL;
}

/**
 * Decrement the reference count of a resource node and free it if it reaches zero.
 * Must be called with the context's uring_lock held.
 */
static inline void io_put_rsrc_node(struct io_ring_ctx *ctx, struct io_rsrc_node *node)
{
	lockdep_assert_held(&ctx->uring_lock);
	if (!--node->refs)
		io_free_rsrc_node(ctx, node);
}

/**
 * Reset (remove and free) a resource node at the given index in the resource data array.
 * Returns true if a node was reset, false otherwise.
 */
static inline bool io_reset_rsrc_node(struct io_ring_ctx *ctx,
				      struct io_rsrc_data *data, int index)
{
	struct io_rsrc_node *node = data->nodes[index];

	if (!node)
		return false;
	io_put_rsrc_node(ctx, node);
	data->nodes[index] = NULL;
	return true;
}

/**
 * Release all resource nodes held by a request (file and buffer nodes).
 * Decrements reference counts and sets pointers to NULL.
 */
static inline void io_req_put_rsrc_nodes(struct io_kiocb *req)
{
	if (req->file_node) {
		io_put_rsrc_node(req->ctx, req->file_node);
		req->file_node = NULL;
	}
	if (req->flags & REQ_F_BUF_NODE) {
		io_put_rsrc_node(req->ctx, req->buf_node);
		req->buf_node = NULL;
	}
}

/**
 * Assign a resource node to a destination pointer and increment its reference count.
 */
static inline void io_req_assign_rsrc_node(struct io_rsrc_node **dst_node,
					   struct io_rsrc_node *node)
{
	node->refs++;
	*dst_node = node;
}

/**
 * Assign a buffer resource node to a request and set the buffer node flag.
 */
static inline void io_req_assign_buf_node(struct io_kiocb *req,
					  struct io_rsrc_node *node)
{
	io_req_assign_rsrc_node(&req->buf_node, node);
	req->flags |= REQ_F_BUF_NODE;
}

/**
 * Update registered files for a request, handling both normal and index-allocated updates.
 */
int io_files_update(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepare a resource update operation from an io_uring_sqe for a request.
 */
int io_files_update_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Account locked memory pages for a user, ensuring limits are not exceeded.
 */
int __io_account_mem(struct user_struct *user, unsigned long nr_pages);

/**
 * Unaccount (release) locked memory pages for a user.
 */
static inline void __io_unaccount_mem(struct user_struct *user,
				      unsigned long nr_pages)
{
	atomic_long_sub(nr_pages, &user->locked_vm);
}

/**
 * Free the memory allocated for an iou_vec structure.
 * Releases the iovec array and resets the structure fields.
 */
void io_vec_free(struct iou_vec *iv);

/**
 * Reallocate the iovec array in an iou_vec structure to a new size.
 * Frees the old array and allocates a new one.
 */
int io_vec_realloc(struct iou_vec *iv, unsigned nr_entries);

/**
 * Reset the iovec pointer and count in an iou_vec structure.
 * Frees the old array and assigns the new one.
 */
static inline void io_vec_reset_iovec(struct iou_vec *iv,
				      struct iovec *iovec, unsigned nr)
{
	io_vec_free(iv);
	iv->iovec = iovec;
	iv->nr = nr;
}

/**
 * Free the iovec array in an iou_vec structure if KASAN is enabled.
 */
static inline void io_alloc_cache_vec_kasan(struct iou_vec *iv)
{
	if (IS_ENABLED(CONFIG_KASAN))
		io_vec_free(iv);
}

#endif
