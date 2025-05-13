// SPDX-License-Identifier: GPL-2.0

/**
 * Prepare sync_file_range operation parameters from the submission queue entry (SQE).
 * Extracts offset, length, and flags for the sync operation and sets up the request.
 */
int io_sfr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Execute the sync_file_range system call with the prepared parameters.
 * Synchronizes a file's data and metadata within the specified range.
 */
int io_sync_file_range(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepare fsync operation parameters from the submission queue entry (SQE).
 * Extracts flags, offset, and length for the fsync operation and sets up the request.
 */
int io_fsync_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Execute the fsync system call with the prepared parameters.
 * Flushes file data and metadata to disk for the specified range.
 */
int io_fsync(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Execute the fallocate system call with the prepared parameters.
 * Allocates or manipulates space for a file as specified by the mode, offset, and length.
 */
int io_fallocate(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepare fallocate operation parameters from the submission queue entry (SQE).
 * Extracts offset, length, and mode for the fallocate operation and sets up the request.
 */
int io_fallocate_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
