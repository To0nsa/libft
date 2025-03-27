/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:44:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:04:21 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 * @brief Duplicates a null-terminated string.
 *
 * This file contains the implementation of `ft_strdup`, which creates a
 * newly allocated copy of a string using `malloc`.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Allocates and duplicates a null-terminated string.
 *
 * Allocates memory for a copy of the string `src`, copies its contents
 * (including the null terminator), and returns a pointer to the new string.
 *
 * @param src The source string to duplicate.
 * @return A pointer to the newly allocated string, or NULL on allocation
 * failure.
 *
 * @see ft_strlcpy
 * @see ft_strlen
 * @ingroup string_utils
 */
char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	src_len;

	src_len = ft_strlen(src);
	copy = (char *)malloc((src_len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, src_len + 1);
	return (copy);
}
