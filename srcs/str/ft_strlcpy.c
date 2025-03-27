/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:46:27 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:09:08 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcpy.c
 * @brief Safely copies a string with buffer size limitation.
 *
 * This file provides the implementation of `ft_strlcpy`, which copies a
 * string from `src` to `dest` ensuring null-termination, and avoiding buffer
 * overflows. The function mimics the behavior of the standard `strlcpy`.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Copies a string from `src` to `dest`, up to `size` - 1 characters.
 *
 * Copies up to `size - 1` characters from the null-terminated string `src`
 * to `dest`, null-terminating the result. If `size` is 0, nothing is written
 * to `dest`, but the length of `src` is still returned.
 *
 * @param dest Destination buffer.
 * @param src Source null-terminated string to copy.
 * @param size Total size of destination buffer.
 *
 * @return The length of `src`. This allows detection of truncation:
 *         if the return value is >= `size`, truncation occurred.
 *
 * @ingroup string_utils
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
