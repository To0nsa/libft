/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:47:33 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:13:28 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strncmp.c
 * @brief Compares two strings up to a given number of characters.
 *
 * This file provides an implementation of the `strncmp` function,
 * which compares at most `n` characters of two strings.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Compares two strings up to `n` characters.
 *
 * This function compares the first `n` characters of the strings
 * `s1` and `s2`. The comparison is done using unsigned characters.
 *
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @param n  Maximum number of characters to compare.
 *
 * @return An integer less than, equal to, or greater than 0 if `s1`
 *         is found, respectively, to be less than, to match, or be
 *         greater than `s2`.
 *
 * @note The comparison stops when a difference is found, a null byte
 *       is encountered, or `n` characters have been compared.
 *
 * @ingroup string_utils
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
