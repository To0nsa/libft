/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:41:32 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:04:25 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memset.c
 * @brief Fills a block of memory with a constant byte.
 *
 * This file contains the implementation of `ft_memset`, which sets the first
 * @p n bytes of the memory area pointed to by @p s to the specified byte @p c.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup memory_utils
 */
#include "libft.h"

/**
 * @brief Fills memory with a constant byte.
 *
 * This function sets each of the first @p n bytes of the memory area pointed
 * to by @p s to the constant byte value @p c (converted to an unsigned char).
 *
 * @param s Pointer to the memory area to fill.
 * @param c Byte value to fill the memory with.
 * @param n Number of bytes to fill.
 *
 * @return A pointer to the memory area @p s.
 *
 * @note Useful for initializing memory to zero or another value.
 *
 * @ingroup memory_utils
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
