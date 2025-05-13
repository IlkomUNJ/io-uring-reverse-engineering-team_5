// SPDX-License-Identifier: GPL-2.0

/* - Prepares a tee request by validating the SQE and setting parameters */
int io_tee_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/* - Executes a tee operation to duplicate data from input to output pipe */
int io_tee(struct io_kiocb *req, unsigned int issue_flags);

/* - Cleans up any resources associated with a splice request */
void io_splice_cleanup(struct io_kiocb *req);

/* - Prepares a splice request by reading SQE offsets and flags */
int io_splice_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/* - Executes a splice operation to transfer data between file descriptors */
int io_splice(struct io_kiocb *req, unsigned int issue_flags);
