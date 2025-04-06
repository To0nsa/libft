/**
 * @file ft_memory.c
 * @author Toonsa
 * @date 2025/04/05
 * @brief Low-level memory manipulation utilities.
 *
 * @details
 * This file implements utility functions for memory allocation,
 * initialization, comparison, and manipulation. It extends or replaces
 * behaviors from the C standard library with consistent, safer versions.
 *
 * The functions are part of the `memory_utils` module and include
 * zeroing memory, copying and moving memory safely, and reallocating blocks.
 *
 * @ingroup memory_utils
 */

#include "libft.h"

/**
 * @brief Sets a block of memory to zero.
 *
 * @details
 * Sets the first @p n bytes of the memory area pointed to by @p s
 * to zero ('\0' bytes). Useful for initializing buffers or memory blocks.
 *
 * @param s Pointer to the memory area to zero out.
 * @param n Number of bytes to set to zero.
 * @return Nothing.
 *
 * @note Behaves similarly to the standard `bzero` function. Often used
 * with `malloc`, `calloc`, or custom memory allocators.
 *
 * @see ft_memset
 * @ingroup memory_utils
 */
void ft_bzero(void* s, size_t n)
{
	unsigned char* ptr;
	size_t         i;

	ptr = (unsigned char*) s;
	i   = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

/**
 * @brief Fills memory with a constant byte.
 *
 * @details
 * Sets the first @p n bytes of the memory area pointed to by @p s
 * to the byte value @p c, converted to unsigned char.
 *
 * @param s Pointer to the memory area to fill.
 * @param c Byte value to write into memory.
 * @param n Number of bytes to write.
 * @return A pointer to the memory area @p s.
 *
 * @ingroup memory_utils
 */
void* ft_memset(void* s, int c, size_t n)
{
	unsigned char* ptr;
	size_t         i;

	ptr = (unsigned char*) s;
	i   = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/**
 * @brief Scans memory for a specific byte.
 *
 * @details
 * Searches the first @p n bytes of the memory area pointed to by @p s
 * for the first occurrence of the byte @p c.
 *
 * @param s Pointer to the memory block to scan.
 * @param c Byte to search for.
 * @param n Number of bytes to scan.
 * @return A pointer to the matching byte, or NULL if not found.
 *
 * @ingroup memory_utils
 */
void* ft_memchr(const void* s, int c, size_t n)
{
	const unsigned char* ptr;
	size_t               i;

	ptr = (const unsigned char*) s;
	i   = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return ((void*) (ptr + i));
		i++;
	}
	return (NULL);
}

/**
 * @brief Compares two memory blocks.
 *
 * @details
 * Compares the first @p n bytes of memory areas @p s1 and @p s2.
 * Comparison is done byte by byte using unsigned characters.
 *
 * @param s1 Pointer to the first memory block.
 * @param s2 Pointer to the second memory block.
 * @param n Number of bytes to compare.
 * @return Difference between first differing bytes, or 0 if equal.
 *
 * @ingroup memory_utils
 */
int ft_memcmp(const void* s1, const void* s2, size_t n)
{
	const unsigned char* ptr1;
	const unsigned char* ptr2;
	size_t               i;

	ptr1 = (const unsigned char*) s1;
	ptr2 = (const unsigned char*) s2;
	i    = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/**
 * @brief Copies memory from source to destination.
 *
 * @details
 * Copies @p n bytes from @p src to @p dest. Performs fast 8-byte chunks
 * when possible. Does not support overlapping memory regions.
 *
 * @param dest Pointer to destination memory.
 * @param src Pointer to source memory.
 * @param n Number of bytes to copy.
 * @return A pointer to @p dest, or NULL if either pointer is NULL.
 *
 * @warning Use `ft_memmove` instead when memory regions overlap.
 *
 * @ingroup memory_utils
 */
void* ft_memcpy(void* dest, const void* src, size_t n)
{
	unsigned char*       d8;
	const unsigned char* s8;

	d8 = (unsigned char*) dest;
	s8 = (const unsigned char*) src;
	if (!dest || !src)
		return (NULL);
	if (dest == src)
		return (dest);
	while (n >= 8)
	{
		*(uint64_t*) d8 = *(const uint64_t*) s8;
		d8 += 8;
		s8 += 8;
		n -= 8;
	}
	while (n--)
		*d8++ = *s8++;
	return (dest);
}

/**
 * @brief Copies memory safely, handling overlapping regions.
 *
 * @details
 * Copies @p n bytes from @p src to @p dest. Chooses forward or backward
 * copy direction based on pointer alignment to avoid corruption.
 *
 * @param dest Pointer to destination memory.
 * @param src Pointer to source memory.
 * @param n Number of bytes to copy.
 * @return A pointer to @p dest.
 *
 * @note This function is safe for overlapping memory regions.
 *
 * @see ft_memcpy
 * @ingroup memory_utils
 */
void* ft_memmove(void* dest, const void* src, size_t n)
{
	unsigned char*       d;
	const unsigned char* s;

	if (!n)
		return (dest);
	d = (unsigned char*) dest;
	s = (const unsigned char*) src;
	if (d > s && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

/**
 * @brief Allocates and zeroes memory for an array.
 *
 * @details
 * Allocates memory for @p nmemb elements of @p size bytes each and
 * initializes all memory to zero. Includes overflow protection.
 *
 * @param nmemb Number of elements.
 * @param size Size of each element in bytes.
 * @return Pointer to the allocated memory, or NULL on failure.
 *
 * @note Equivalent to `malloc(nmemb * size)` followed by `ft_memset(ptr, 0,
 * ...)`.
 *
 * @see ft_memset
 * @ingroup memory_utils
 */
void* ft_calloc(size_t nmemb, size_t size)
{
	void*  ptr;
	size_t total_size;

	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	if (total_size == 0)
		return (malloc(0));
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

/**
 * @brief Resizes a memory block.
 *
 * @details
 * Allocates new memory of size @p new_size, copies up to @p old_size bytes
 * from @p ptr into the new block, and frees the old memory.
 *
 * @param ptr Pointer to previously allocated memory.
 * @param old_size Size of the old block.
 * @param new_size Desired new size.
 * @return Pointer to new memory block, or NULL on failure.
 *
 * @note If @p ptr is NULL, behaves like `malloc(new_size)`.
 *       If @p new_size is 0, frees memory and returns NULL.
 *
 * @see ft_memmove
 * @ingroup memory_utils
 */
void* ft_realloc(void* ptr, size_t old_size, size_t new_size)
{
	void*  new_ptr;
	size_t copy_size;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	copy_size = (old_size < new_size) ? old_size : new_size;
	ft_memmove(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
