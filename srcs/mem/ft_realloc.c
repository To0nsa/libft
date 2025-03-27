/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:14:23 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:04:19 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_realloc.c
 * @brief Reallocates a memory block to a new size.
 *
 * This file implements `ft_realloc`, a memory utility function that resizes
 * an existing memory block, preserving its content up to the minimum of the
 * old and new sizes.
 * 
 * It mimics the behavior of the standard C `realloc` function but is
 * implemented manually using `malloc` and `ft_memmove`.
 *
 * @author nlouis
 * @date 2024/11/08
 * @ingroup memory_utils
 */
#include "libft.h"

/**
 * @brief Reallocates a memory block to a new size.
 *
 * Allocates a new block of memory with size @p new_size, copies up to
 * @p old_size bytes from the original @p ptr into the new block, and
 * frees the old memory.
 *
 * If @p ptr is NULL, this function behaves like `malloc(new_size)`.
 * If @p new_size is 0, frees the memory and returns NULL.
 * If allocation fails, returns NULL and the original memory is not freed.
 *
 * @param ptr Pointer to the previously allocated memory block.
 * @param old_size The size of the old memory block in bytes.
 * @param new_size The desired new size in bytes.
 *
 * @return A pointer to the new memory block, or NULL on failure.
 *
 * @note The content beyond the old size is uninitialized.
 *
 * @see ft_memmove
 * @ingroup memory_utils
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
