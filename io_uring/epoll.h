// SPDX-License-Identifier: GPL-2.0

#if defined(CONFIG_EPOLL)
// Prepares epoll_ctl data from SQE (epfd, op, fd, and event if provided).
int io_epoll_ctl_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Executes epoll_ctl (ADD/MOD/DEL) based on prepared data.
int io_epoll_ctl(struct io_kiocb *req, unsigned int issue_flags);

// Prepares epoll_wait data from SQE (event count and user buffer pointer).
int io_epoll_wait_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

// Sends available epoll events to user buffer or returns EAGAIN if none available.
int io_epoll_wait(struct io_kiocb *req, unsigned int issue_flags);
#endif
