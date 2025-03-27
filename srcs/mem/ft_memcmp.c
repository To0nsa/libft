/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:40:06 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:04:42 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcmp.c
 * @brief Compares two memory areas byte by byte.
 *
 * This file provides the implementation of `ft_memcmp`, which performs a 
 * lexicographical comparison between two memory blocks.
 * It is typically used to compare raw memory contents.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup memory_utils
 */
#include "libft.h"

/**
 * @brief Compares two memory blocks.
 *
 * This function compares the first @p n bytes of memory areas 
 * @p s1 and @p s2. The comparison is done byte-by-byte using 
 * unsigned characters.
 *
 * @param s1 Pointer to the first memory block.
 * @param s2 Pointer to the second memory block.
 * @param n Number of bytes to compare.
 *
 * @return An integer less than, equal to, or greater than zero 
 *         if the first @p n bytes of @p s1 are found, respectively, 
 *         to be less than, to match, or be greater than those of @p s2.
 *
 * @note The comparison stops at the first differing byte or after 
 *       @p n bytes.
 *
 * @ingroup memory_utils
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
