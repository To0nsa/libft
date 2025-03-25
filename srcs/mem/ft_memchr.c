/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:38:49 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:20:05 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memchr()
 * Locates the first occurrence of a byte in a memory block.
 *
 * @s: Pointer to the memory area to search.
 * @c: Byte value to look for (converted to unsigned char).
 * @n: Number of bytes to examine.
 *
 * Returns: A pointer to the first occurrence of c in s,
 *          or NULL if c is not found within the first n bytes.
 *
 * Usage:
 * - Useful for scanning raw memory for a specific byte value.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
