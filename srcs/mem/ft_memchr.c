/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:38:49 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:04:47 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memchr.c
 * @brief Locates the first occurrence of a byte in a memory area.
 *
 * This file contains the implementation of `ft_memchr`, a function
 * that searches for the first occurrence of a byte in a memory block.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup memory_utils
 */
#include "libft.h"

/**
 * @brief Scans memory for the first occurrence of a specific byte.
 *
 * This function scans the initial @p n bytes of the memory area
 * pointed to by @p s for the first instance of the byte @p c
 * (converted to an `unsigned char`). If the byte is found, a
 * pointer to the matching byte is returned.
 *
 * @param s Pointer to the memory block to be scanned.
 * @param c Byte to search for, interpreted as unsigned char.
 * @param n Number of bytes to scan.
 *
 * @return A pointer to the matching byte in memory, or NULL if
 *         the byte is not found in the first @p n bytes.
 *
 * @ingroup memory_utils
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
