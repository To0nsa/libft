/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:18:26 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:02:57 by nlouis           ###   ########.fr       */
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
 * @date 2025/01/28
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
 * @ingroup string_utils
 */
char	*ft_strcpy(char *dst, const char *src)
{
	char	*ret;

	ret = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
