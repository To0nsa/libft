/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:44:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:25:53 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strdup()
 * Duplicates a string by allocating memory and copying the content.
 *
 * @src: The source string to duplicate.
 *
 * Returns: A pointer to the newly allocated copy of the string,
 *          or NULL if allocation fails.
 *
 * Notes:
 * - The new string is null-terminated.
 * - Uses malloc() and ft_strlcpy() for allocation and copying.
 * - The caller is responsible for freeing the returned string.
 */
char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	src_len;

	src_len = ft_strlen(src);
	copy = (char *)malloc((src_len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, src_len + 1);
	return (copy);
}
