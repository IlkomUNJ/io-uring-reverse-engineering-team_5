// SPDX-License-Identifier: GPL-2.0
#ifndef IORING_REGISTER_H
#define IORING_REGISTER_H

/**
 * Unregister the eventfd from the io_uring context.
 * Used to remove eventfd notification support.
 */
int io_eventfd_unregister(struct io_ring_ctx *ctx);

/**
 * Unregister a previously registered personality from the io_uring context.
 * Releases associated credentials.
 */
int io_unregister_personality(struct io_ring_ctx *ctx, unsigned id);

/**
 * Get the file pointer for a given fd, either from the registered ring fds or the normal fd table.
 * Returns a file pointer or error.
 */
struct file *io_uring_register_get_file(unsigned int fd, bool registered);

#endif
