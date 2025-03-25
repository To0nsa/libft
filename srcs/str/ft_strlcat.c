/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:45:53 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:27:55 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcat()
 * Appends src to the end of dest, up to size - 1 characters.
 *
 * @dest: The destination string (must be null-terminated).
 * @src: The source string to append.
 * @size: Total size of the destination buffer.
 *
 * Returns: The total length of the string it tried to create:
 *          - If return >= size, truncation occurred.
 *          - If return < size, all of src was appended.
 *
 * Notes:
 * - Always null-terminates the result (if size > 0).
 * - Does nothing if size <= strlen(dest).
 * - Safe alternative to strcat, prevents buffer overflows.
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
