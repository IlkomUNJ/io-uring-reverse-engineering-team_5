// SPDX-License-Identifier: GPL-2.0

/**
 * Prepare statx operation parameters from the submission queue entry (SQE).
 * Validates and extracts file descriptor, mask, path, flags, and output buffer.
 * Sets up the request for asynchronous statx execution and cleanup.
 */
int io_statx_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Execute the statx system call with the prepared parameters.
 * Retrieves file status and metadata, then sets the result for the request.
 */
int io_statx(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Cleanup resources allocated for the statx operation, such as filename.
 */
void io_statx_cleanup(struct io_kiocb *req);
