/**
 * @file ft_memory.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief Low-level memory manipulation functions.
 *
 * @details
 * This header declares utility functions for memory operations such as
 * allocation, zeroing, copying, moving, comparison, and searching.
 *
 * These functions replicate or improve upon standard C library behaviors
 * while ensuring better consistency and safety in custom C projects.
 *
 * @ingroup memory_utils
 */

#ifndef FT_MEMORY_H
#define FT_MEMORY_H

/**
 * @defgroup memory_utils Memory Management
 * @brief Functions for low-level memory operations.
 *
 * @details
 * This group contains functions that replicate or extend common C
 * standard library memory operations, including:
 *
 * - Allocation (`ft_calloc`, `ft_realloc`)
 * - Initialization (`ft_bzero`, `ft_memset`)
 * - Copying and moving (`ft_memcpy`, `ft_memmove`)
 * - Comparison and search (`ft_memcmp`, `ft_memchr`)
 *
 * These utilities provide safer or more convenient alternatives to their
 * standard counterparts and are useful throughout custom C projects.
 *
 * This group includes:
 * - @ref ft_calloc
 * - @ref ft_realloc
 * - @ref ft_bzero
 * - @ref ft_memchr
 * - @ref ft_memcmp
 * - @ref ft_memcpy
 * - @ref ft_memmove
 * - @ref ft_memset
 * @{
 */

void* ft_calloc(size_t count, size_t size);
void* ft_realloc(void* ptr, size_t old_size, size_t new_size);
void  ft_bzero(void* s, size_t n);
void* ft_memchr(const void* buffer, int c, size_t count);
int   ft_memcmp(const void* buffer1, const void* buffer2, size_t count);
void* ft_memcpy(void* dest, const void* src, size_t count);
void* ft_memmove(void* dest, const void* src, size_t count);
void* ft_memset(void* dest, int c, size_t count);

/** @} */ // end of memory_utils group

#endif
