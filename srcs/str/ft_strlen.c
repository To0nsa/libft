/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:46:47 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:11:07 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlen.c
 * @brief Computes the length of a null-terminated string.
 *
 * This file contains the implementation of the `ft_strlen` function,
 * which calculates the number of characters in a C string before
 * the null terminator.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Returns the number of characters in a string.
 *
 * Iterates through the given null-terminated string to determine
 * its length (not including the terminating `\0`).
 *
 * @param str The string whose length is to be calculated.
 * @return The number of characters before the null terminator.
 *
 * @ingroup string_utils
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
