// SPDX-License-Identifier: GPL-2.0

int io_madvise_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe); // Prepares the IO operation for `madvise` system call.
int io_madvise(struct io_kiocb *req, unsigned int issue_flags); // Executes the `madvise` system call.
int io_fadvise_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe); // Prepares the IO operation for `fadvise` system call.
int io_fadvise(struct io_kiocb *req, unsigned int issue_flags); // Executes the `fadvise` system call.
