// SPDX-License-Identifier: GPL-2.0

#include <linux/net.h>
#include <linux/uio.h>
#include <net/sock.h>
#include <linux/nospec.h>

#include "rsrc.h"

#define IO_NOTIF_UBUF_FLAGS	(SKBFL_ZEROCOPY_FRAG | SKBFL_DONT_ORPHAN)
#define IO_NOTIF_SPLICE_BATCH	32

/**
 * Holds state for an io_uring notification, including file, buffer info,
 * chaining, memory accounting, and zero-copy status.
 */
struct io_notif_data {
	struct file		*file;
	struct ubuf_info	uarg;

	struct io_notif_data	*next;
	struct io_notif_data	*head;

	unsigned		account_pages;
	bool			zc_report;
	bool			zc_used;
	bool			zc_copied;
};

/*
 * io_alloc_notif() - Allocates and initializes a new notification object, 
 * setting up the necessary fields, including zero-copy flags and memory 
 * accounting information.
 */
struct io_kiocb *io_alloc_notif(struct io_ring_ctx *ctx);

/*
 * io_tx_ubuf_complete() - Finalizes the transmission of the zero-copy buffer, 
 * marking the completion of the task and updating related flags.
 */
void io_tx_ubuf_complete(struct sk_buff *skb, struct ubuf_info *uarg,
			 bool success);

/*
 * io_notif_to_data() - Converts a given io_kiocb to its associated 
 * io_notif_data structure, allowing easy access to the notification data.
 */
static inline struct io_notif_data *io_notif_to_data(struct io_kiocb *notif)
{
	return io_kiocb_to_cmd(notif, struct io_notif_data);
}

/*
 * io_notif_flush() - Flushes the notification, ensuring the zero-copy buffer 
 * is completed and processed before proceeding.
 */
static inline void io_notif_flush(struct io_kiocb *notif)
	__must_hold(&notif->ctx->uring_lock)
{
	struct io_notif_data *nd = io_notif_to_data(notif);

	io_tx_ubuf_complete(NULL, &nd->uarg, true);
}

/*
 * io_notif_account_mem() - Accounts for memory usage by the notification, 
 * increasing the memory counter based on the length of the notification data.
 */
static inline int io_notif_account_mem(struct io_kiocb *notif, unsigned len)
{
	struct io_ring_ctx *ctx = notif->ctx;
	struct io_notif_data *nd = io_notif_to_data(notif);
	unsigned nr_pages = (len >> PAGE_SHIFT) + 2;
	int ret;

	if (ctx->user) {
		ret = __io_account_mem(ctx->user, nr_pages);
		if (ret)
			return ret;
		nd->account_pages += nr_pages;
	}
	return 0;
}
