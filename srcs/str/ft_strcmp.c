/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:26:04 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:01:52 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strcmp.c
 * @brief Compares two strings lexicographically.
 *
 * This file contains the implementation of `ft_strcmp`, which compares
 * two null-terminated strings character by character.
 * 
 * @author nlouis
 * @date 2024/12/01
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Compares two strings lexicographically.
 *
 * This function compares the characters of `s1` and `s2` one by one.
 * The comparison stops at the first differing character or when a null byte
 * is reached.
 *
 * @param s1 Pointer to the first null-terminated string.
 * @param s2 Pointer to the second null-terminated string.
 * @return An integer less than, equal to, or greater than 0 if `s1` is found
 *         to be less than, equal to, or greater than `s2`, respectively.
 *
 * @note The comparison is done using unsigned char values.
 *
 * @see ft_strncmp
 * @see ft_strcmp
 * @ingroup string_utils
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
