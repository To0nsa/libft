/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:19:56 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:41:45 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_utoa.c
 * @brief Converts an unsigned long long integer to a string.
 *
 * This file contains the implementation of `ft_utoa`, which converts an unsigned
 * long long integer to its string representation. It allocates memory for the
 * resulting string, handles the case for zero, and returns the string representation.
 *
 * @author nlouis
 * @date 2024/11/08
 * @ingroup number_conversions
 */
#include "libft.h"

/**
 * @brief Converts an unsigned long long integer to a string.
 *
 * This function converts an unsigned long long integer `n` into its string
 * representation. The function allocates memory for the string, which must be
 * freed by the caller. If the input number is zero, the string "0" is returned.
 *
 * @param n The unsigned long long integer to convert to a string.
 *
 * @return A dynamically allocated string representing `n`, or `NULL` if memory
 *         allocation fails.
 *
 * @ingroup number_conversions
 */
char	*ft_utoa(unsigned long long n)
{
	char					*str;
	size_t					len;
	unsigned long long		temp_num;

	len = 1;
	temp_num = n;
	while (temp_num >= 10)
	{
		temp_num /= 10;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
