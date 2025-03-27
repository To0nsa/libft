/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:40:38 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:04:37 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 * @brief Copies bytes from one memory area to another.
 *
 * This file provides the implementation of `ft_memcpy`, an optimized 
 * memory copy function that uses 64-bit chunks where possible.
 * It is typically used for copying raw memory blocks.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup memory_utils
 */
#include "libft.h"

/**
 * @brief Copies @p n bytes from @p src to @p dest.
 *
 * This function performs a memory copy from the source pointer @p src 
 * to the destination pointer @p dest. It copies 64-bit chunks when 
 * possible for performance, then completes with byte-by-byte copying.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 *
 * @return A pointer to the destination memory area @p dest.
 *
 * @note If either @p dest or @p src is NULL, the function returns NULL.
 *       This implementation handles overlapping memory incorrectly and 
 *       should not be used when overlap is possible — use `ft_memmove` 
 *       instead in such cases.
 *
 * @ingroup memory_utils
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d8;
	const unsigned char	*s8;

	d8 = (unsigned char *)dest;
	s8 = (const unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	if (dest == src)
		return (dest);
	while (n >= 8)
	{
		*(uint64_t *)d8 = *(const uint64_t *)s8;
		d8 += 8;
		s8 += 8;
		n -= 8;
	}
	while (n--)
		*d8++ = *s8++;
	return (dest);
}
