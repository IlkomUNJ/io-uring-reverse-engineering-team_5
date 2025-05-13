#ifndef IO_URING_MEMMAP_H
#define IO_URING_MEMMAP_H

// Defines the offset for the parameter region in the mmap space
#define IORING_MAP_OFF_PARAM_REGION		0x20000000ULL
// Defines the offset for the zcrx region in the mmap space
#define IORING_MAP_OFF_ZCRX_REGION		0x30000000ULL

// Pins the user-space pages in memory for the given address range
struct page **io_pin_pages(unsigned long ubuf, unsigned long len, int *npages);

#ifndef CONFIG_MMU
// Returns the mmap capabilities for non-MMU systems
unsigned int io_uring_nommu_mmap_capabilities(struct file *file);
#endif

// Returns the address of the first unmapped area for a file's mmap request
unsigned long io_uring_get_unmapped_area(struct file *file, unsigned long addr,
					 unsigned long len, unsigned long pgoff,
					 unsigned long flags);

// Handles the memory mapping for io_uring regions
int io_uring_mmap(struct file *file, struct vm_area_struct *vma);

// Frees a mapped region and releases any associated resources
void io_free_region(struct io_ring_ctx *ctx, struct io_mapped_region *mr);

// Creates a new memory region for io_uring
int io_create_region(struct io_ring_ctx *ctx, struct io_mapped_region *mr,
		     struct io_uring_region_desc *reg,
		     unsigned long mmap_offset);

// Creates a memory region for io_uring and ensures it's mmap-safe
int io_create_region_mmap_safe(struct io_ring_ctx *ctx,
				struct io_mapped_region *mr,
				struct io_uring_region_desc *reg,
				unsigned long mmap_offset);

// Returns a pointer to the memory of the mapped region
static inline void *io_region_get_ptr(struct io_mapped_region *mr)
{
	return mr->ptr;
}

// Checks if the memory region is properly set
static inline bool io_region_is_set(struct io_mapped_region *mr)
{
	return !!mr->nr_pages;
}

#endif
