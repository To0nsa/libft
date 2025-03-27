/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:17 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:15:54 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strrchr.c
 * @brief Finds the last occurrence of a character in a string.
 *
 * This file contains the implementation of the `ft_strrchr` function, which
 * returns a pointer to the last occurrence of a character in a string.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Returns a pointer to the last occurrence of a character in a string.
 *
 * Scans the string `str` for the last occurrence of the character `c`
 * (interpreted as an unsigned char). If found, a pointer to the character
 * is returned. If not, NULL is returned.
 *
 * If `c` is '\0', a pointer to the null terminator at the end of the string
 * is returned.
 *
 * @param str The null-terminated string to be searched.
 * @param c   The character to search for (casted to `unsigned char`).
 *
 * @return A pointer to the last occurrence of `c` in `str`, or NULL if not
 *         found.
 *
 * @ingroup string_utils
 */
char	*ft_strrchr(const char *str, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last_occurrence = (char *)str;
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (last_occurrence);
}
