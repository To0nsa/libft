/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:35:45 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:04:52 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 * @brief Allocates and zero-initializes an array in memory.
 *
 * This file contains the implementation of `ft_calloc`, which allocates
 * memory for an array of elements and initializes all bytes to zero.
 * It is a safer alternative to `malloc` as it includes overflow protection.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup memory_utils
 */
#include "libft.h"

/**
 * @brief Allocates and zero-initializes memory for an array.
 *
 * This function allocates memory for an array of @p nmemb elements of
 * @p size bytes each and initializes all bytes in the allocated memory
 * to zero. It also includes overflow protection for `nmemb * size`.
 *
 * @param nmemb Number of elements to allocate.
 * @param size  Size in bytes of each element.
 *
 * @return A pointer to the allocated memory, or NULL if the allocation
 *         fails or if an overflow is detected.
 *
 * @note The returned memory must be freed using `free` when no longer used.
 *
 * @see ft_memset
 * @see malloc
 * @ingroup memory_utils
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

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
