/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:53 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:21:36 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_substr.c
 * @brief Extracts a substring from a string.
 *
 * This file contains the implementation of the `ft_substr` function,
 * which creates a new string from the source string `s` starting at
 * index `start` and taking up to `len` characters. If `start` is beyond
 * the length of the string, an empty string is returned. If memory allocation
 * fails, NULL is returned.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Extracts a substring from a string.
 *
 * Allocates and returns a new string, which is a substring of `s` starting from
 * index `start` and up to `len` characters long. If `start` is greater than or equal
 * to the length of `s`, an empty string is returned. The length of the returned substring
 * is either `len` or the remaining length from `start`, whichever is smaller.
 *
 * @param s The source string.
 * @param start The starting index in the source string.
 * @param len The maximum number of characters to copy.
 *
 * @return A newly allocated string containing the substring, or NULL if memory allocation fails.
 *         If `start` is out of bounds, an empty string is returned.
 *
 * @see ft_strlen
 * @see ft_strlcpy
 * @ingroup string_utils
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			str_len;
	size_t			max_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		substr = (char *)malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	max_len = str_len - start;
	if (max_len > len)
		max_len = len;
	substr = (char *)malloc((max_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, max_len + 1);
	return (substr);
}
