// SPDX-License-Identifier: GPL-2.0

/*
 * Removes a fixed file descriptor from the fixed file table
 * after acquiring the submit lock.
 */
int __io_close_fixed(struct io_ring_ctx *ctx, unsigned int issue_flagsa,
		     unsigned int offset);

/*
 * Reads mode and flags from the SQE, constructs an open_how
 * structure, and delegates to __io_openat_prep() for further setup.
 */
int io_openat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Handles the io_uring openat operation by calling io_openat2(),
 * acting as a wrapper.
 */
int io_openat(struct io_kiocb *req, unsigned int issue_flags);

/*
 * Frees the filename resource allocated during request preparation.
 */
void io_open_cleanup(struct io_kiocb *req);

/*
 * Copies the open_how structure from userspace and calls
 * __io_openat_prep() to continue preparation.
 */
int io_openat2_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Executes the file open operation using the specified flags,
 * handles file descriptor allocation or fixed slot installation.
 */
int io_openat2(struct io_kiocb *req, unsigned int issue_flags);

/*
 * Parses and validates fields for a close operation from the SQE,
 * ensuring no unsupported flags are set.
 */
int io_close_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Closes a regular or fixed file descriptor, checking for async flush needs
 * and handling both paths safely.
 */
int io_close(struct io_kiocb *req, unsigned int issue_flags);

/*
 * Validates parameters and flags for installing
 * a file into a fixed slot, and checks for permission issues.
 */
int io_install_fixed_fd_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * Installs the file associated with the request into
 * a fixed file descriptor table and sets the result in the request.
 */
int io_install_fixed_fd(struct io_kiocb *req, unsigned int issue_flags);
