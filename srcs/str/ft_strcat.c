/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:24:25 by riamaev           #+#    #+#             */
/*   Updated: 2025/03/26 12:36:00 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strcat.c
 * @brief Concatenates one string to the end of another.
 *
 * This file contains the implementation of `ft_strcat`, which appends the
 * source string to the destination string, assuming the destination has
 * enough space to hold the result.
 *
 * @author nlouis
 * @date 2025/03/09
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Appends the `src` string to the end of the `dest` string.
 *
 * This function assumes that `dest` points to a buffer large enough to hold
 * the resulting string, including the null terminator.
 *
 * @param dest The destination string to which `src` will be appended.
 * @param src The source string to append.
 * @return A pointer to the destination string (`dest`).
 *
 * @note The behavior is undefined if the destination buffer is not large
 *       enough to contain the result.
 *
 * @ingroup string_utils
 */
char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*dest_ptr)
		dest_ptr++;
	while (*src)
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}
	*dest_ptr = '\0';
	return (dest);
}
