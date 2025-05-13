// SPDX-License-Identifier: GPL-2.0

#include <linux/net.h>
#include <linux/uio.h>
#include <linux/io_uring_types.h>

/**
 * io_async_msghdr - Stores async message header state for network operations.
 * @vec: IO vector for data transfer.
 * @namelen: Length of the socket address.
 * @fast_iov: Fast-path iovec for small transfers.
 * @controllen: Length of control data.
 * @payloadlen: Length of payload data.
 * @uaddr: User-space address pointer.
 * @msg: Kernel msghdr structure for message passing.
 * @addr: Storage for socket address.
 *
 * Used to manage async send/recvmsg state, iovec, and address info for io_uring net ops.
 */
struct io_async_msghdr {
#if defined(CONFIG_NET)
	struct iou_vec				vec;

	struct_group(clear,
		int				namelen;
		struct iovec			fast_iov;
		__kernel_size_t			controllen;
		__kernel_size_t			payloadlen;
		struct sockaddr __user		*uaddr;
		struct msghdr			msg;
		struct sockaddr_storage		addr;
	);
#else
	struct_group(clear);
#endif
};

#if defined(CONFIG_NET)

/**
 * Prepares a shutdown request by validating SQE fields and setting shutdown mode.
 * Returns 0 on success or -EINVAL on invalid input.
 */
int io_shutdown_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Performs a socket shutdown operation using the parameters in the request.
 * Returns IOU_OK on completion or -ENOTSOCK if the file is not a socket.
 */
int io_shutdown(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Cleans up resources associated with sendmsg/recvmsg async data in a request.
 */
void io_sendmsg_recvmsg_cleanup(struct io_kiocb *req);
/**
 * Prepares a sendmsg request, validates flags, and allocates async data.
 * Returns 0 on success or negative error code on failure.
 */
int io_sendmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Performs a sendmsg operation on a socket, handling retries and completion logic.
 * Returns IOU_OK on completion or negative error code on failure.
 */
int io_sendmsg(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Performs a send operation on a socket, handling buffer selection and retries.
 * Returns result of the send or negative error code on failure.
 */
int io_send(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepares a recvmsg request, validates flags, and allocates async data.
 * Returns 0 on success or negative error code on failure.
 */
int io_recvmsg_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Performs a recvmsg operation on a socket, handling multishot and completion logic.
 * Returns result of the receive or negative error code on failure.
 */
int io_recvmsg(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Performs a recv operation on a socket, handling buffer selection and retries.
 * Returns result of the receive or negative error code on failure.
 */
int io_recv(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Handles failure for send/recv operations, setting error state in the request.
 */
void io_sendrecv_fail(struct io_kiocb *req);

/**
 * Prepares an accept request by validating SQE fields and setting up address info.
 * Returns 0 on success or negative error code on failure.
 */
int io_accept_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Performs an accept operation on a socket, returning a new file descriptor.
 * Returns result of the accept or negative error code on failure.
 */
int io_accept(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepares a socket creation request by validating SQE fields and parameters.
 * Returns 0 on success or negative error code on failure.
 */
int io_socket_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Performs a socket creation operation, returning a new socket file descriptor.
 * Returns result of the socket creation or negative error code on failure.
 */
int io_socket(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepares a connect request by validating SQE fields and address info.
 * Returns 0 on success or negative error code on failure.
 */
int io_connect_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Performs a connect operation on a socket, establishing a connection.
 * Returns result of the connect or negative error code on failure.
 */
int io_connect(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Performs a zero-copy send operation on a socket.
 * Returns result of the send or negative error code on failure.
 */
int io_send_zc(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Performs a zero-copy sendmsg operation on a socket.
 * Returns result of the sendmsg or negative error code on failure.
 */
int io_sendmsg_zc(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Prepares a zero-copy send request by validating SQE fields and parameters.
 * Returns 0 on success or negative error code on failure.
 */
int io_send_zc_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Cleans up resources associated with zero-copy send operations.
 */
void io_send_zc_cleanup(struct io_kiocb *req);

/**
 * Prepares a bind request by validating SQE fields and address info.
 * Returns 0 on success or negative error code on failure.
 */
int io_bind_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Performs a bind operation on a socket, associating it with an address.
 * Returns result of the bind or negative error code on failure.
 */
int io_bind(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Prepares a listen request by validating SQE fields and backlog.
 * Returns 0 on success or negative error code on failure.
 */
int io_listen_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);
/**
 * Performs a listen operation on a socket, enabling it to accept connections.
 * Returns result of the listen or negative error code on failure.
 */
int io_listen(struct io_kiocb *req, unsigned int issue_flags);

/**
 * Frees or recycles an async message header cache entry for network operations.
 */
void io_netmsg_cache_free(const void *entry);
#else
static inline void io_netmsg_cache_free(const void *entry)
{
}
#endif
