/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:45:53 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:07:43 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcat.c
 * @brief Appends a string to another with buffer size limitation.
 *
 * This file contains the implementation of `ft_strlcat`, which safely
 * concatenates two strings with a size limit, ensuring null-termination.
 * It mimics the behavior of the standard `strlcat` function.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Concatenates `src` to the end of `dest` while ensuring null-termination.
 *
 * This function appends the `src` string to the end of the `dest` string.
 * It ensures that the result fits within the buffer size given by `size`,
 * including the null-terminator. If `size` is less than or equal to the
 * length of `dest`, the function returns `size + strlen(src)` without
 * appending.
 *
 * @param dest The destination buffer.
 * @param src The source string to append.
 * @param size The total size of the destination buffer.
 *
 * @return The total length of the string it tried to create:
 *         `strlen(dest) + strlen(src)`.
 *         This value can be used to detect truncation.
 *
 * @see ft_strlen
 * @see ft_strlcpy
 * @ingroup string_utils
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	space_left;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	total_len = dest_len + src_len;
	space_left = size - dest_len;
	ft_strlcpy(dest + dest_len, src, space_left);
	return (total_len);
}
