// SPDX-License-Identifier: GPL-2.0

// Prepares the io_renameat operation by extracting and validating relevant data from the request.
int io_renameat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Executes the io_renameat operation, performing the actual rename.
int io_renameat(struct io_kiocb *req, unsigned int issue_flags);

// Cleans up resources used during the io_renameat operation.
void io_renameat_cleanup(struct io_kiocb *req);

// Prepares the io_unlinkat operation by extracting and validating relevant data from the request.
int io_unlinkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Executes the io_unlinkat operation, performing the actual unlink (or rmdir if directory).
int io_unlinkat(struct io_kiocb *req, unsigned int issue_flags);

// Cleans up resources used during the io_unlinkat operation.
void io_unlinkat_cleanup(struct io_kiocb *req);

// Prepares the io_mkdirat operation by extracting and validating relevant data from the request.
int io_mkdirat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Executes the io_mkdirat operation, performing the actual directory creation.
int io_mkdirat(struct io_kiocb *req, unsigned int issue_flags);

// Cleans up resources used during the io_mkdirat operation.
void io_mkdirat_cleanup(struct io_kiocb *req);

// Prepares the io_symlinkat operation by extracting and validating relevant data from the request.
int io_symlinkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Executes the io_symlinkat operation, performing the actual symlink creation.
int io_symlinkat(struct io_kiocb *req, unsigned int issue_flags);

// Prepares the io_linkat operation by extracting and validating relevant data from the request.
int io_linkat_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Executes the io_linkat operation, performing the actual hard link creation.
int io_linkat(struct io_kiocb *req, unsigned int issue_flags);

// Cleans up resources used during the io_linkat operation.
void io_link_cleanup(struct io_kiocb *req);
