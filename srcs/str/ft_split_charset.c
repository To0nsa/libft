/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:38:15 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:35:41 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split_charset.c
 * @brief Splits a string into substrings based on a set of delimiters.
 *
 * This file provides the implementation of `ft_split_charset`, a utility
 * function that splits a string into an array of substrings, using a set
 * of characters as delimiters (charset).
 * Each substring is dynamically allocated.
 *
 * Helper functions are defined as static for internal use:
 * - `ft_is_charset`: checks if a character is in the charset.
 * - `ft_w_count_charset`: counts the number of substrings (words).
 * - `ft_fill_array_charset`: fills the output array with substrings.
 *
 * @author nlouis
 * @date 2025/02/08
 * @ingroup string_utils
 */
#include "libft.h"


/**
 * @brief Checks if a character belongs to a charset.
 *
 * @param c The character to check.
 * @param charset The set of delimiter characters.
 * @return 1 if the character is in the charset, 0 otherwise.
 */
static int	ft_is_charset(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

/**
 * @brief Counts how many substrings will result from splitting.
 *
 * @param str The input string to split.
 * @param charset The set of delimiter characters.
 * @return The number of substrings (fields) expected in the result.
 */
static size_t	ft_w_count_charset(char *str, char *charset)
{
	size_t	count;
	int		in_field;

	count = 0;
	in_field = 1;
	while (*str)
	{
		if (ft_is_charset(*str, charset))
		{
			count++;
			in_field = 1;
		}
		else if (in_field)
		{
			in_field = 0;
		}
		str++;
	}
	return (count + 1);
}

/**
 * @brief Fills the array with substrings from the input string.
 *
 * @param array The output array of substrings.
 * @param s The input string to split.
 * @param charset The set of delimiter characters.
 * @param field_count The number of substrings to extract.
 * @return 1 on success, 0 on allocation failure.
 *
 * @see ft_substr
 * @see ft_free_array
 */
static int	ft_fill_array_charset(char **array, char *s,
										char *charset, size_t field_count)
{
	size_t	i;
	size_t	field_len;

	i = 0;
	while (i < field_count)
	{
		field_len = 0;
		while (s[field_len] && !ft_is_charset(s[field_len], charset))
			field_len++;
		array[i] = ft_substr(s, 0, field_len);
		if (!array[i])
		{
			ft_free_array((void **)array);
			return (0);
		}
		s += field_len;
		if (*s)
			s++;
		i++;
	}
	array[i] = NULL;
	return (1);
}

/**
 * @brief Splits a string into substrings based on a character set.
 *
 * This function uses a charset (set of delimiters) to split the string
 * `s` into a NULL-terminated array of substrings.
 *
 * @param s The string to split.
 * @param charset The set of delimiter characters.
 * @return A newly allocated array of substrings, or NULL on error.
 *
 * @see ft_w_count_charset
 * @see ft_fill_array_charset
 * @see ft_free_array
 * @ingroup string_utils
 */
char	**ft_split_charset(char *s, char *charset)
{
	char		**array;
	size_t		field_count;

	if (!s || !charset)
		return (NULL);
	field_count = ft_w_count_charset(s, charset);
	array = (char **)ft_calloc(field_count + 1, sizeof(char *));
	if (!array)
		return (NULL);
	if (!ft_fill_array_charset(array, s, charset, field_count))
	{
		free(array);
		return (NULL);
	}
	return (array);
}
