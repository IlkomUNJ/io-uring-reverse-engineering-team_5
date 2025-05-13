// SPDX-License-Identifier: GPL-2.0
#ifndef IOU_ZC_RX_H
#define IOU_ZC_RX_H

#include <linux/io_uring_types.h>
#include <linux/socket.h>
#include <net/page_pool/types.h>
#include <net/net_trackers.h>

/**
 * Holds state for a zero-copy RX area, including net IOV area, interface queue,
 * user references, mapping info, area ID, page array, and freelist management.
 */
struct io_zcrx_area {
	struct net_iov_area	nia;
	struct io_zcrx_ifq	*ifq;
	atomic_t		*user_refs;

	bool			is_mapped;
	u16			area_id;
	struct page		**pages;

	/* freelist */
	spinlock_t		freelist_lock ____cacheline_aligned_in_smp;
	u32			free_count;
	u32			*freelist;
};

/**
 * Holds state for a zero-copy RX interface queue, including context, area,
 * ring pointers, queue entries, device info, and locking.
 */
struct io_zcrx_ifq {
	struct io_ring_ctx		*ctx;
	struct io_zcrx_area		*area;

	struct io_uring			*rq_ring;
	struct io_uring_zcrx_rqe	*rqes;
	u32				rq_entries;
	u32				cached_rq_head;
	spinlock_t			rq_lock;

	u32				if_rxq;
	struct device			*dev;
	struct net_device		*netdev;
	netdevice_tracker		netdev_tracker;
	spinlock_t			lock;
};

#if defined(CONFIG_IO_URING_ZCRX)
/**
 * Register a zero-copy RX interface queue for the given io_uring context.
 * Sets up structures and memory for zero-copy receive operations.
 */
int io_register_zcrx_ifq(struct io_ring_ctx *ctx,
			 struct io_uring_zcrx_ifq_reg __user *arg);
/**
 * Unregister all zero-copy RX interface queues for the given io_uring context.
 * Cleans up and releases all associated resources.
 */
void io_unregister_zcrx_ifqs(struct io_ring_ctx *ctx);
/**
 * Shutdown all zero-copy RX interface queues for the given io_uring context.
 * Ensures all buffers are reclaimed and queues are closed.
 */
void io_shutdown_zcrx_ifqs(struct io_ring_ctx *ctx);
/**
 * Receive data using zero-copy from the specified interface queue and socket.
 * Handles TCP receive logic and fills user buffers with received data.
 */
int io_zcrx_recv(struct io_kiocb *req, struct io_zcrx_ifq *ifq,
		 struct socket *sock, unsigned int flags,
		 unsigned issue_flags, unsigned int *len);
#else
static inline int io_register_zcrx_ifq(struct io_ring_ctx *ctx,
					struct io_uring_zcrx_ifq_reg __user *arg)
{
	return -EOPNOTSUPP;
}
static inline void io_unregister_zcrx_ifqs(struct io_ring_ctx *ctx)
{
}
static inline void io_shutdown_zcrx_ifqs(struct io_ring_ctx *ctx)
{
}
static inline int io_zcrx_recv(struct io_kiocb *req, struct io_zcrx_ifq *ifq,
			       struct socket *sock, unsigned int flags,
			       unsigned issue_flags, unsigned int *len)
{
	return -EOPNOTSUPP;
}
#endif

/**
 * Issue a zero-copy receive operation for the given request.
 * Used as the main entry point for RECV_ZC io_uring operations.
 */
int io_recvzc(struct io_kiocb *req, unsigned int issue_flags);
/**
 * Prepare a zero-copy receive operation from the submission queue entry.
 * Validates and sets up the request for RECV_ZC.
 */
int io_recvzc_prep(struct io_kiocb *req, const struct io_uring_sqe *sqe);

#endif
