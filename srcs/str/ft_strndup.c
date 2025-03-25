/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:10:39 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:31:20 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strndup()
 * Duplicates up to n characters from a string into a new allocation.
 *
 * @src: The source string to duplicate.
 * @n: Maximum number of characters to copy.
 *
 * Returns: A newly allocated string containing at most n characters from @src,
 *			null-terminated. Returns NULL if allocation fails.
 *
 * Notes:
 * - If @n is greater than the length of @src, duplicates the entire string.
 * - The caller is responsible for freeing the returned string.
 * - Safer alternative when working with partial strings or bounded buffers.
 */

char	*ft_strndup(const char *src, size_t n)
{
	char	*copy;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (n < src_len)
		src_len = n;
	copy = (char *)malloc((src_len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, src_len + 1);
	return (copy);
}
