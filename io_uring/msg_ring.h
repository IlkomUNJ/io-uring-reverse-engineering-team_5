// SPDX-License-Identifier: GPL-2.0

// Prepares the message ring for synchronous processing. 
// Verifies the input parameters and sets up the necessary message structure.
int io_uring_sync_msg_ring(struct io_uring_sqe *sqe);

// Prepares the message ring operation by initializing the io_msg structure 
// based on the io_uring_sqe input, checking for invalid configurations.
int io_msg_ring_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Main function to handle message ring operations. It processes 
// different types of message operations such as data sending and file descriptor passing.
int io_msg_ring(struct io_kiocb *req, unsigned int issue_flags);

// Cleans up resources associated with a message ring operation, 
// specifically handling cleanup of the source file in the message structure.
void io_msg_ring_cleanup(struct io_kiocb *req);
