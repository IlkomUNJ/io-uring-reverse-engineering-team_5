// SPDX-License-Identifier: GPL-2.0

// Displays internal io_uring context information (e.g., SQ/CQ status, user files, buffers, and thread stats) to /proc.
void io_uring_show_fdinfo(struct seq_file *m, struct file *f);
