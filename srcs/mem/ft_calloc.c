/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:35:45 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:19:11 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_calloc()
 * Allocates memory for an array and initializes it to zero.
 *
 * @nmemb: Number of elements.
 * @size: Size of each element.
 *
 * Returns: A pointer to the allocated memory, or NULL on failure or overflow.
 *
 * Usage:
 * - Similar to the standard calloc().
 * - Performs an overflow check: (nmemb * size) must be safe.
 * - If total size is 0, still returns malloc(0) for conformity.
 * - Memory is zeroed using ft_memset().
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
