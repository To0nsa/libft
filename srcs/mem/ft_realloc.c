/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:14:23 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:22:51 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_realloc()
 * Reallocates a memory block to a new size, preserving existing data.
 *
 * @ptr: Pointer to the currently allocated memory block.
 * @old_size: Size of the current memory block.
 * @new_size: Desired new size of the memory block.
 *
 * Returns: A pointer to the newly allocated memory,
 *			or NULL if allocation fails or new_size is 0.
 *
 * Behavior:
 * - If ptr is NULL, behaves like malloc(new_size).
 * - If new_size is 0, frees ptr and returns NULL.
 * - If new_size == old_size, returns the original pointer.
 * - Otherwise, allocates new memory, copies the data, frees the old block.
 *
 * Usage:
 * - Safe wrapper to resize a block while preserving its content.
 */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

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
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memmove(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
