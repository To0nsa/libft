/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:33:58 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:35:50 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 * @brief Splits a string into substrings using a single delimiter.
 *
 * This file contains the implementation of the `ft_split` function, which
 * divides a string into an array of substrings based on a single character
 * delimiter. Each substring is dynamically allocated.
 *
 * Helper functions:
 * - `ft_w_count`: counts the number of substrings (words).
 * - `ft_fill_array`: fills the array with allocated substrings.
 *
 * @author nlouis
 * @date 2024/12/12
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Counts how many substrings will result from splitting.
 *
 * @param str The input string to scan.
 * @param c The delimiter character.
 * @return The number of substrings (words) in the input.
 */
static size_t	ft_w_count(const char *str, char c)
{
	size_t	w_count;
	int		in_word;

	w_count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			w_count++;
			in_word = 1;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (w_count);
}

/**
 * @brief Fills the output array with substrings from input.
 *
 * Each substring is allocated using `ft_substr`, and the array is NULL-
 * terminated. On allocation failure, previously allocated strings are freed.
 *
 * @param array The output array of substrings.
 * @param s The input string to split.
 * @param c The delimiter character.
 * @param w_count The number of substrings to extract.
 * @return 1 on success, 0 on failure.
 *
 * @see ft_substr
 * @see ft_free_array
 */
static int	ft_fill_array(char **array, const char *s, char c, size_t w_count)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (i < w_count)
	{
		while (*s == c)
			s++;
		word_len = 0;
		while (s[word_len] && s[word_len] != c)
			word_len++;
		array[i] = ft_substr(s, 0, word_len);
		if (!array[i])
		{
			ft_free_array((void **)array);
			return (0);
		}
		s += word_len;
		i++;
	}
	array[i] = NULL;
	return (1);
}

/**
 * @brief Splits a string into substrings based on a delimiter character.
 *
 * Allocates and returns a NULL-terminated array of substrings resulting from
 * splitting the input string by the delimiter character.
 *
 * @param s The string to split.
 * @param c The delimiter character.
 * @return A newly allocated array of substrings, or NULL on failure.
 *
 * @see ft_w_count
 * @see ft_fill_array
 * @see ft_substr
 * @see ft_free_array
 * @ingroup string_utils
 */
char	**ft_split(const char *s, char c)
{
	char		**array;
	size_t		w_count;

	if (!s)
		return (NULL);
	w_count = ft_w_count(s, c);
	array = (char **)ft_calloc(w_count + 1, sizeof(char *));
	if (!array)
		return (NULL);
	if (!ft_fill_array(array, s, c, w_count))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
