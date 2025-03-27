/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:35 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:18:24 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtrim.c
 * @brief Trims characters from the beginning and end of a string.
 *
 * This file contains the implementation of `ft_strtrim`, a function that
 * removes all leading and trailing characters from a string `s1` that
 * are present in the `set` string.
 *
 * Helper functions include logic to identify where to start and stop
 * the trimming.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Checks if a character is present in a given set.
 *
 * @param c The character to check.
 * @param set The null-terminated string containing the set of characters.
 * @return 1 if `c` is in `set`, 0 otherwise.
 */
static int	ft_is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Finds the starting index after trimming leading characters.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return The index of the first character not in `set`.
 */
static size_t	ft_trim_start(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	return (start);
}

/**
 * @brief Finds the ending index before trimming trailing characters.
 *
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return The index of the last character not in `set` + 1.
 */
static size_t	ft_trim_end(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0 && ft_is_in_set(s1[end - 1], set))
		end--;
	return (end);
}

/**
 * @brief Trims characters from both ends of a string.
 *
 * Allocates and returns a copy of the string `s1` with the characters
 * specified in `set` removed from the beginning and end.
 *
 * @param s1 The original null-terminated string to trim.
 * @param set The set of characters to trim.
 * @return A newly allocated trimmed string, or NULL on allocation failure.
 *
 * @note If the resulting trimmed string is empty, a string containing only
 *       '\0' is returned.
 *
 * @see ft_trim_start
 * @see ft_trim_end
 * @see ft_strlcpy
 * @ingroup string_utils
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;
	size_t	copy_size;

	if (!s1 || !set)
		return (NULL);
	start = ft_trim_start(s1, set);
	end = ft_trim_end(s1, set);
	copy_size = end - start;
	if (start >= end)
	{
		trimmed_str = (char *)malloc(sizeof(char));
		if (!trimmed_str)
			return (NULL);
		trimmed_str[0] = '\0';
		return (trimmed_str);
	}
	trimmed_str = (char *)malloc((copy_size + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + start, copy_size + 1);
	return (trimmed_str);
}
