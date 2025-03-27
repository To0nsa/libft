/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:13:08 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:26:41 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file skip_whitespace.c
 * @brief Skips whitespace characters in a string.
 *
 * This file contains two functions that are used to skip over whitespace
 * characters in a string. One function operates on an index, and the other
 * returns a pointer to the first non-whitespace character in the string.
 *
 * @author nlouis
 * @date 2025/03/26
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Returns a pointer to the first non-whitespace character in a string.
 *
 * This function returns a pointer to the first character in the string `s`
 * that is not a whitespace character. If the string consists only of
 * whitespace characters, it returns a pointer to the null-terminator.
 *
 * @param s The string to search for non-whitespace characters.
 *
 * @return A pointer to the first non-whitespace character in the string,
 *         or the null-terminator if no such character exists.
 *
 * @see skip_whitespace_index
 * @ingroup string_utils
 */
void	skip_whitespace_index(const char *input, int *i)
{
	while (ft_isspace(input[*i]))
		(*i)++;
}

/**
 * @brief Increments the index while skipping whitespace characters.
 *
 * This function iterates through the `input` string from the position
 * indicated by the index `*i`, incrementing the index until a non-whitespace
 * character is encountered. It is commonly used for string parsing where
 * leading spaces need to be skipped.
 *
 * @param input The string to search for whitespace.
 * @param i The current index in the string, which will be incremented
 *          to skip whitespace characters.
 *
 * @see skip_whitespace_ptr
 * @ingroup string_utils
 */
char	*skip_whitespace_ptr(const char *s)
{
	while (ft_isspace(*s))
		s++;
	return ((char *)s);
}
