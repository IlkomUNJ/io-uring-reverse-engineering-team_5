/* SPDX-License-Identifier: GPL-2.0 */

#ifndef IOU_NAPI_H
#define IOU_NAPI_H

#include <linux/kernel.h>
#include <linux/io_uring.h>
#include <net/busy_poll.h>

#ifdef CONFIG_NET_RX_BUSY_POLL

// Initialize NAPI settings in the io_ring_ctx.
void io_napi_init(struct io_ring_ctx *ctx);

// Free NAPI resources in the io_ring_ctx.
void io_napi_free(struct io_ring_ctx *ctx);

// Register NAPI settings in the io_ring_ctx.
int io_register_napi(struct io_ring_ctx *ctx, void __user *arg);

// Unregister NAPI settings from the io_ring_ctx.
int io_unregister_napi(struct io_ring_ctx *ctx, void __user *arg);

// Add NAPI ID to the io_ring_ctx for busy polling.
int __io_napi_add_id(struct io_ring_ctx *ctx, unsigned int napi_id);

// Perform a busy poll loop for NAPI in the io_ring_ctx.
void __io_napi_busy_loop(struct io_ring_ctx *ctx, struct io_wait_queue *iowq);

// Perform busy poll for SQPOLL in the io_ring_ctx.
int io_napi_sqpoll_busy_poll(struct io_ring_ctx *ctx);

// Check if NAPI is enabled in the io_ring_ctx.
static inline bool io_napi(struct io_ring_ctx *ctx)
{
	return !list_empty(&ctx->napi_list);
}

// Execute the busy poll loop if NAPI is enabled.
static inline void io_napi_busy_loop(struct io_ring_ctx *ctx,
				     struct io_wait_queue *iowq)
{
	if (!io_napi(ctx))
		return;
	__io_napi_busy_loop(ctx, iowq);
}

/*
 * io_napi_add() - Add napi id to the busy poll list
 * @req: pointer to io_kiocb request
 *
 * Add the napi id of the socket to the napi busy poll list and hash table.
 */
static inline void io_napi_add(struct io_kiocb *req)
{
	struct io_ring_ctx *ctx = req->ctx;
	struct socket *sock;

	if (READ_ONCE(ctx->napi_track_mode) != IO_URING_NAPI_TRACKING_DYNAMIC)
		return;

	sock = sock_from_file(req->file);
	if (sock && sock->sk)
		__io_napi_add_id(ctx, READ_ONCE(sock->sk->sk_napi_id));
}

#else

// No-op functions when CONFIG_NET_RX_BUSY_POLL is not enabled.

static inline void io_napi_init(struct io_ring_ctx *ctx)
{
}

// No-op for freeing NAPI resources when CONFIG_NET_RX_BUSY_POLL is not enabled.
static inline void io_napi_free(struct io_ring_ctx *ctx)
{
}

// Return -EOPNOTSUPP when registering NAPI is not supported.
static inline int io_register_napi(struct io_ring_ctx *ctx, void __user *arg)
{
	return -EOPNOTSUPP;
}

// Return -EOPNOTSUPP when unregistering NAPI is not supported.
static inline int io_unregister_napi(struct io_ring_ctx *ctx, void __user *arg)
{
	return -EOPNOTSUPP;
}

// Return false to indicate NAPI is not enabled when CONFIG_NET_RX_BUSY_POLL is not available.
static inline bool io_napi(struct io_ring_ctx *ctx)
{
	return false;
}

// No-op for adding NAPI ID when busy polling is not enabled.
static inline void io_napi_add(struct io_kiocb *req)
{
}

// No-op for busy poll loop when CONFIG_NET_RX_BUSY_POLL is not available.
static inline void io_napi_busy_loop(struct io_ring_ctx *ctx,
				     struct io_wait_queue *iowq)
{
}

// Return 0 to indicate no busy polling is available when CONFIG_NET_RX_BUSY_POLL is not enabled.
static inline int io_napi_sqpoll_busy_poll(struct io_ring_ctx *ctx)
{
	return 0;
}
#endif /* CONFIG_NET_RX_BUSY_POLL */

#endif
