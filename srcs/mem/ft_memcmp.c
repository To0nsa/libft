/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:40:06 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:20:55 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memcmp()
 * Compares two memory areas byte by byte.
 *
 * @s1: Pointer to the first memory area.
 * @s2: Pointer to the second memory area.
 * @n: Number of bytes to compare.
 *
 * Returns: An integer less than, equal to, or greater than zero:
 *			- < 0 if s1 < s2
 *			- = 0 if s1 == s2
 *			- > 0 if s1 > s2
 *          Comparison is done using unsigned byte values.
 *
 * Usage:
 * - Useful for comparing raw memory blocks or binary data.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				i;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
