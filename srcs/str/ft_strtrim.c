/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:35 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:33:37 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_is_in_set()
 * Checks if a character is present in the given set.
 *
 * @c: The character to check.
 * @set: The set of characters to search in.
 *
 * Returns: 1 if @c is found in @set, 0 otherwise.
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
 * ft_trim_start()
 * Calculates the index of the first character in @s1
 * that is not in @set.
 *
 * @s1: The input string.
 * @set: The set of characters to trim.
 *
 * Returns: The index of the first character to keep.
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
 * ft_trim_end()
 * Calculates the index just after the last character in @s1
 * that is not in @set.
 *
 * @s1: The input string.
 * @set: The set of characters to trim.
 *
 * Returns: The index one past the last character to keep.
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
 * ft_strtrim()
 * Trims all characters from the beginning and end of a string that are
 * present in the given set.
 *
 * @s1: The input string to trim.
 * @set: The set of characters to remove from both ends of @s1.
 *
 * Returns: A newly allocated trimmed string,
 *          or NULL if allocation fails or if inputs are NULL.
 *
 * Notes:
 * - Uses helper functions to find start and end indexes to copy.
 * - If the entire string is trimmed, returns an empty string.
 * - Caller is responsible for freeing the returned string.
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
