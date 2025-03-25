/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:41:02 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:22:03 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memmove()
 * Copies n bytes from src to dest, handling overlapping memory safely.
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source buffer.
 * @n: Number of bytes to copy.
 *
 * Returns: A pointer to the destination buffer.
 *
 * Usage:
 * - Safe for overlapping memory areas (unlike ft_memcpy).
 * - If dest overlaps src and is higher in memory, copying is done backward.
 * - If not overlapping or dest < src, copying is done forward.
 * - Does nothing if n == 0.
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
