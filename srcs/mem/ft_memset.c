/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:41:32 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:22:23 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memset()
 * Fills a block of memory with a constant byte.
 *
 * @s: Pointer to the memory area to fill.
 * @c: Byte value to set (converted to unsigned char).
 * @n: Number of bytes to fill.
 *
 * Returns: A pointer to the memory area @s.
 *
 * Usage:
 * - Sets the first @n bytes of the memory block to the byte value @c.
 * - Commonly used to initialize memory (e.g., to 0 or -1).
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
