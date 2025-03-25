/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:46:27 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:29:01 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlcpy()
 * Copies a string into a buffer, ensuring null-termination.
 *
 * @dest: The destination buffer.
 * @src: The source string to copy.
 * @size: The size of the destination buffer.
 *
 * Returns: The total length of the source string (excluding null terminator).
 *
 * Notes:
 * - Copies up to size - 1 characters from src to dest.
 * - Always null-terminates dest if size > 0.
 * - Return value allows detection of truncation:
 *	- If return >= size, the copy was truncated.
 *	- If return < size, the full string was copied.
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
