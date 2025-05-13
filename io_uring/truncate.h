// SPDX-License-Identifier: GPL-2.0

/**
 * Prepares the ftruncate operation by parsing and validating the SQE (submission queue entry).
 * Sets up the io_kiocb request for a file truncate operation.
 */
int io_ftruncate_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Executes the ftruncate operation on the file associated with the io_kiocb request.
 * Truncates the file to the specified length, handling the provided issue flags.
 */
int io_ftruncate(struct io_kiocb *req, unsigned int issue_flags);
