// SPDX-License-Identifier: GPL-2.0

#include "alloc_cache.h"

/*
 * Frees all entries in the allocation cache and clears the cache structure.
 * This function iterates over all the entries in the cache and frees them using the provided `free` function. After that, the memory used for the cache entry array is freed, and the cache is reset to NULL.
 */
void io_alloc_cache_free(struct io_alloc_cache *cache,
			 void (*free)(const void *))
{
	void *entry;

	if (!cache->entries)
		return;

	while ((entry = io_alloc_cache_get(cache)) != NULL)
		free(entry);

	kvfree(cache->entries);
	cache->entries = NULL;
}

/*
 * Initializes the allocation cache with the given parameters.
 * This function sets up the cache to store up to `max_nr` elements, with each element of size `size`. It also takes `init_bytes` to initialize memory.
 * Returns `true` if cache initialization fails, and `false` if successful.
 */
bool io_alloc_cache_init(struct io_alloc_cache *cache,
			 unsigned max_nr, unsigned int size,
			 unsigned int init_bytes)
{
	cache->entries = kvmalloc_array(max_nr, sizeof(void *), GFP_KERNEL);
	if (!cache->entries)
		return true;

	cache->nr_cached = 0;
	cache->max_cached = max_nr;
	cache->elem_size = size;
	cache->init_clear = init_bytes;
	return false;
}

/*
 * Allocates a new object from the cache with the given flags.
 * It uses `kmalloc` to allocate memory and clears it if `init_clear` is set.
 */
void *io_cache_alloc_new(struct io_alloc_cache *cache, gfp_t gfp)
{
	void *obj;

	obj = kmalloc(cache->elem_size, gfp);
	if (obj && cache->init_clear)
		memset(obj, 0, cache->init_clear);
	return obj;
}
