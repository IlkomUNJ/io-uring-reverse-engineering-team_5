// SPDX-License-Identifier: GPL-2.0

/*
 * io_nop_prep() - Prepares the NOP operation by extracting relevant flags, 
 * file descriptor, and buffer index from the SQE (Submission Queue Entry).
 */
int io_nop_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

/*
 * io_nop() - Executes the NOP operation, handling file and buffer operations 
 * based on the specified flags, and setting the result for the request.
 */
int io_nop(struct io_kiocb *req, unsigned int issue_flags);
