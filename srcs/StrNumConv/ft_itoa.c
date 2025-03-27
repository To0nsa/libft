/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:38:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:39:41 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 * @brief Converts a long long integer to a string.
 *
 * This file contains the implementation of `ft_itoa`, which converts a
 * long long integer to its string representation. It handles both positive
 * and negative numbers and allocates memory for the resulting string.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup number_conversions
 */
#include "libft.h"

/**
 * @brief Calculates the length of the number when converted to a string.
 *
 * This helper function calculates how many digits are required to represent
 * a long long integer `n` as a string. It also accounts for the negative sign
 * if the number is negative and the zero case.
 *
 * @param n The long long integer whose length is to be calculated.
 *
 * @return The number of digits required to represent `n` as a string.
 *
 * @see ft_itoa
 * @ingroup number_conversions
 */
static size_t	ft_nlen(long long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * @brief Converts a long long integer to a string.
 *
 * This function converts a long long integer `n` to its string representation.
 * It handles the case where `n` is zero and also handles negative numbers by
 * adding a minus sign. The function allocates memory for the resulting string,
 * which must be freed by the caller.
 *
 * @param n The long long integer to convert to a string.
 *
 * @return A dynamically allocated string representing `n`. Returns `NULL` if
 *         memory allocation fails.
 *
 * @see ft_nlen
 * @ingroup number_conversions
 */
char	*ft_itoa(long long n)
{
	char				*str;
	size_t				len;
	unsigned long long	num;

	len = ft_nlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		num = (unsigned long long)(-n);
	}
	else
		num = (unsigned long long)n;
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
