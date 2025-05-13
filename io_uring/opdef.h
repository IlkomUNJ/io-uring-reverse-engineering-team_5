// SPDX-License-Identifier: GPL-2.0
#ifndef IOU_OP_DEF_H
#define IOU_OP_DEF_H

/**
 * io_issue_def - Describes the properties and handlers for an io_uring opcode.
 * Contains flags for operation requirements, async data size, and pointers to
 * the preparation and issue functions for the opcode.
 */
struct io_issue_def {
	/* needs req->file assigned */
	unsigned		needs_file : 1;
	/* should block plug */
	unsigned		plug : 1;
	/* supports ioprio */
	unsigned		ioprio : 1;
	/* supports iopoll */
	unsigned		iopoll : 1;
	/* op supports buffer selection */
	unsigned		buffer_select : 1;
	/* hash wq insertion if file is a regular file */
	unsigned		hash_reg_file : 1;
	/* unbound wq insertion if file is a non-regular file */
	unsigned		unbound_nonreg_file : 1;
	/* set if opcode supports polled "wait" */
	unsigned		pollin : 1;
	unsigned		pollout : 1;
	unsigned		poll_exclusive : 1;
	/* skip auditing */
	unsigned		audit_skip : 1;
	/* have to be put into the iopoll list */
	unsigned		iopoll_queue : 1;
	/* vectored opcode, set if 1) vectored, and 2) handler needs to know */
	unsigned		vectored : 1;

	/* size of async data needed, if any */
	unsigned short		async_size;

	int (*issue)(struct io_kiocb *, unsigned int);
	int (*prep)(struct io_kiocb *, const struct io_uring_sqe *);
};

/**
 * io_cold_def - Provides cold-path metadata for an io_uring opcode.
 * Contains the operation name and optional cleanup/failure handlers.
 */
struct io_cold_def {
	const char		*name;

	void (*cleanup)(struct io_kiocb *);
	void (*fail)(struct io_kiocb *);
};

/**
 * io_issue_defs - Table of opcode definitions for io_uring operations.
 * Maps each opcode to its properties, preparation, and issue handlers.
 */
extern const struct io_issue_def io_issue_defs[];

/**
 * io_cold_defs - Table of cold-path metadata for io_uring operations.
 * Maps each opcode to its name and optional cleanup/failure handlers.
 */
extern const struct io_cold_def io_cold_defs[];

/**
 * Returns true if the given io_uring opcode is supported by the kernel.
 */
bool io_uring_op_supported(u8 opcode);

/**
 * Initializes the io_uring opcode definition tables and checks for consistency.
 */
void io_uring_optable_init(void);
#endif
