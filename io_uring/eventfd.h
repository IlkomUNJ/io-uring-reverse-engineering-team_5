// Forward declaration of io_ring_ctx structure.
struct io_ring_ctx;

// Registers a new eventfd with context, and stores its state in ev_fd.
int io_eventfd_register(struct io_ring_ctx *ctx, void __user *arg,
			unsigned int eventfd_async);

// Unregisters eventfd from context and releases all references.
int io_eventfd_unregister(struct io_ring_ctx *ctx);

// Sends signal to eventfd only if a new CQE is added.
void io_eventfd_flush_signal(struct io_ring_ctx *ctx);

// Sends signal to eventfd if context has active eventfd.
void io_eventfd_signal(struct io_ring_ctx *ctx);
