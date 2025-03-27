/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:41:02 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:04:31 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 * @brief Safely copies memory blocks, even when they overlap.
 *
 * This file contains the implementation of `ft_memmove`, a function
 * that copies @p n bytes from @p src to @p dest, correctly handling
 * overlapping memory regions by adjusting the direction of copy.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup memory_utils
 */
#include "libft.h"

/**
 * @brief Copies @p n bytes from @p src to @p dest, handling overlap.
 *
 * This function behaves similarly to `ft_memcpy`, but is safe to use
 * when the source and destination memory areas overlap. It chooses
 * forward or backward copying direction based on pointer addresses.
 *
 * @param dest Destination memory area.
 * @param src Source memory area.
 * @param n Number of bytes to copy.
 *
 * @return A pointer to the destination memory area @p dest.
 *
 * @note If @p n is zero, the function returns @p dest immediately.
 *       If memory regions overlap, the function copies from end to
 *       start to prevent data corruption.
 *
 * @see ft_memcpy
 * @see ft_memset
 * @ingroup memory_utils
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!n)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
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
