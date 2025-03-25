/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:43:55 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:24:24 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strchr()
 * Locates the first occurrence of a character in a string.
 *
 * @str: The string to search in.
 * @c: The character to search for (interpreted as a char).
 *
 * Returns: A pointer to the first occurrence of @c in @str,
 *			or NULL if @c is not found.
 *
 * Notes:
 * - If @c is '\0', returns a pointer to the null terminator.
 * - The returned pointer is of type (char *) even if @str is const.
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
