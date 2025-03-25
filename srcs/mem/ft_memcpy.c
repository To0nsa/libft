/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:40:38 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:21:20 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memcpy()
 * Copies n bytes from source memory area to destination.
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the source buffer.
 * @n: Number of bytes to copy.
 *
 * Returns: A pointer to the destination buffer,
 *          or NULL if dest or src is NULL.
 *
 * Notes:
 * - Uses 64-bit chunks when possible for faster copying.
 * - Falls back to byte-by-byte copy for remaining bytes.
 * - Does not handle overlapping memory (use ft_memmove for that).
 * - If dest == src, does nothing and returns dest.
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
