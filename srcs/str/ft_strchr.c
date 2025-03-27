/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:43:55 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:01:59 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strchr.c
 * @brief Locates the first occurrence of a character in a string.
 *
 * This file contains the implementation of `ft_strchr`, which searches for
 * the first occurrence of a character in a null-terminated string.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * Searches for the first occurrence of the character `c` in the string `str`.
 * The terminating null byte (`\0`) is considered part of the string.
 *
 * @param str The null-terminated string to search in.
 * @param c The character to search for, interpreted as an unsigned char.
 * @return A pointer to the first occurrence of `c` in `str`,
 *         or NULL if `c` is not found.
 *
 * @ingroup string_utils
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}
