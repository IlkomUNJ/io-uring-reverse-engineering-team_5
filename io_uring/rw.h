// SPDX-License-Identifier: GPL-2.0

#include <linux/io_uring_types.h>
#include <linux/pagemap.h>

/**
 * Holds metadata state for direct I/O, including a seed and iterator state.
 */
struct io_meta_state {
	u32			seed;
	struct iov_iter_state	iter_meta;
};

/**
 * Holds state for async read/write operations, including iovec, progress,
 * iterator, and union for buffered or direct I/O metadata.
 */
struct io_async_rw {
	struct iou_vec			vec;
	size_t				bytes_done;

	struct_group(clear,
		struct iov_iter			iter;
		struct iov_iter_state		iter_state;
		struct iovec			fast_iov;
		/*
		 * wpq is for buffered io, while meta fields are used with
		 * direct io
		 */
		union {
			struct wait_page_queue		wpq;
			struct {
				struct uio_meta			meta;
				struct io_meta_state		meta_state;
			};
		};
	);
};

/**
 * Prepare a fixed buffer read request from an SQE.
 * Sets up the request to use a pre-registered buffer for reading.
 */
int io_prep_read_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Prepare a fixed buffer write request from an SQE.
 * Sets up the request to use a pre-registered buffer for writing.
 */
int io_prep_write_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Prepare a fixed buffer vectored read request from an SQE.
 * Sets up the request to use a pre-registered iovec for reading.
 */
int io_prep_readv_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Prepare a fixed buffer vectored write request from an SQE.
 * Sets up the request to use a pre-registered iovec for writing.
 */
int io_prep_writev_fixed(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Prepare a vectored read request from an SQE.
 * Sets up the request to use a user-provided iovec for reading.
 */
int io_prep_readv(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Prepare a vectored write request from an SQE.
 * Sets up the request to use a user-provided iovec for writing.
 */
int io_prep_writev(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Prepare a read request from an SQE.
 * Sets up the request for a standard read operation.
 */
int io_prep_read(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Prepare a write request from an SQE.
 * Sets up the request for a standard write operation.
 */
int io_prep_write(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Perform a read operation on the given file descriptor.
 * Handles non-blocking mode, buffer management, and partial reads.
 */
int io_read(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Perform a write operation on the given file descriptor.
 * Handles non-blocking mode, buffer management, and partial writes.
 */
int io_write(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Perform a read operation using a fixed (pre-registered) buffer.
 * Manages pre-registered buffers for efficient I/O.
 */
int io_read_fixed(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Perform a write operation using a fixed (pre-registered) buffer.
 * Manages pre-registered buffers for efficient I/O.
 */
int io_write_fixed(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Cleanup resources for a vectored read/write request.
 * Frees or recycles any allocated iovec or buffer.
 */
void io_readv_writev_cleanup(struct io_kiocb *req);
/**
 * Mark a read/write request as failed and set the result code.
 */
void io_rw_fail(struct io_kiocb *req);
/**
 * Complete a read/write request and notify the completion queue.
 */
void io_req_rw_complete(struct io_kiocb *req, io_tw_token_t tw);
/**
 * Prepare a multishot read request from an SQE.
 * Sets up the request for multiple reads with a single submission.
 */
int io_read_mshot_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Perform a multishot read operation (multiple reads with a single request).
 * Only valid for files that support polling.
 */
int io_read_mshot(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Free the memory and iovec resources used by an async read/write structure.
 */
void io_rw_cache_free(const void *entry);
