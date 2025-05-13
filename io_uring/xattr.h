// SPDX-License-Identifier: GPL-2.0

/**
 * Cleans up resources and memory allocations for an xattr request.
 */
void io_xattr_cleanup(struct io_kiocb *req);

/**
 * Prepares a setxattr request for a file descriptor by parsing SQE fields and allocating kernel buffers.
 */
int io_fsetxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Executes setxattr for a file descriptor and completes the request.
 */
int io_fsetxattr(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepares a setxattr request for a file path by parsing SQE fields and allocating kernel buffers.
 */
int io_setxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Executes setxattr for a file path and completes the request.
 */
int io_setxattr(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepares a getxattr request for a file descriptor by parsing SQE fields and allocating kernel buffers.
 */
int io_fgetxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Executes getxattr for a file descriptor and completes the request.
 */
int io_fgetxattr(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepares a getxattr request for a file path by parsing SQE fields and allocating kernel buffers.
 */
int io_getxattr_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/**
 * Executes getxattr for a file path and completes the request.
 */
int io_getxattr(struct io_kiocb *req, unsigned int issue_flags);
