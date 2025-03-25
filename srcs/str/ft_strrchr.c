/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:17 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:32:05 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strrchr()
 * Locates the last occurrence of a character in a string.
 *
 * @str: The string to search in.
 * @c: The character to find (interpreted as unsigned char).
 *
 * Returns: A pointer to the last occurrence of @c in @str,
 *			or NULL if @c is not found.
 *
 * Notes:
 * - If @c is '\0', returns a pointer to the null terminator.
 * - Scans the entire string and keeps track of the last match.
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
