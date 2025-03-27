/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:10:39 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:13:34 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strndup.c
 * @brief Duplicates a string up to a maximum number of characters.
 *
 * This file contains the implementation of `ft_strndup`, which allocates
 * and returns a new string that is a duplicate of the input `src`, limited
 * to `n` characters.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Creates a copy of a string, up to `n` characters.
 *
 * This function allocates memory and copies at most `n` characters
 * from the string `src` to a new string. The new string is always
 * null-terminated.
 *
 * @param src The source string to duplicate.
 * @param n   The maximum number of characters to copy.
 *
 * @return A pointer to the newly allocated string, or NULL if memory
 *         allocation fails.
 *
 * @see ft_strlcpy
 * @see ft_strlen
 * @ingroup string_utils
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
