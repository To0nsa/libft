/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:47:33 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:30:57 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strncmp()
 * Compares two strings up to n characters.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: Maximum number of characters to compare.
 *
 * Returns: An integer less than, equal to, or greater than zero:
 *			- < 0 if s1 < s2
 *			- = 0 if s1 == s2 (up to n characters)
 *			- > 0 if s1 > s2
 *
 * Notes:
 * - Comparison stops at the first differing character,
 *	a null terminator, or after n characters.
 * - Characters are compared as unsigned values.
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
