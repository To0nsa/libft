/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:26:04 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:25:07 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strcmp()
 * Compares two strings lexicographically.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Returns: An integer less than, equal to, or greater than zero:
 *			- < 0 if s1 < s2
 *			- = 0 if s1 == s2
 *			- > 0 if s1 > s2
 *
 * Notes:
 * - Comparison is done using unsigned char values.
 * - Stops at the first differing character or at the null terminator.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
