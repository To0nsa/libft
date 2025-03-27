/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:00:10 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:34:06 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoll.c
 * @brief Converts a string to a long long integer (ft_atoll).
 *
 * This file contains the implementation of the `ft_atoll` function, which converts
 * a string representation of a number to a `long long` integer. The function handles
 * optional leading signs (`+` or `-`), whitespace characters, and ensures that
 * overflow is avoided during conversion.
 *
 * The helper function `ft_check_overflow` is used to check for potential overflow
 * conditions while converting the string.
 *
 * @author nlouis
 * @date 2025/10/20
 * @ingroup number_conversions
 */
#include "libft.h"

/**
 * @brief Checks if the result of the ongoing conversion would overflow.
 *
 * This helper function checks whether converting a string to a `long long` would
 * cause an overflow. It compares the current value being accumulated with the maximum
 * and minimum values allowed for a `long long` integer to prevent overflow.
 *
 * @param num The current number being formed during the conversion.
 * @param digit The current digit being processed in the string.
 * @param sign The sign of the number being processed: 1 for positive, -1 for negative.
 *
 * @return True if overflow would occur, false otherwise.
 *
 * @see ft_atoll
 * @ingroup number_conversions
 */
static bool	ft_check_overflow(long long num, char digit, int sign)
{
	long long	cutoff;

	if (sign == 1)
		cutoff = INT_MAX / 10;
	else
		cutoff = (-(long long)INT_MIN) / 10;
	if (sign == 1)
	{
		if (num > cutoff || (num == cutoff && (digit - '0') > (INT_MAX % 10)))
			return (true);
	}
	else
	{
		if (-num > -((long long)INT_MIN / 10)
			|| (-num == -((long long)INT_MIN / 10)
				&& (digit - '0') > ((-(long long)INT_MIN) % 10)))
			return (true);
	}
	return (false);
}

/**
 * @brief Converts a string to a long long integer (ft_atoll).
 *
 * This function converts a string to a `long long` integer, considering an optional
 * leading sign (`+` or `-`) and handling whitespace characters. The function reads
 * each digit, converts it to an integer, and checks for overflow using the
 * `ft_check_overflow` helper function. It stops parsing when a non-digit character
 * is encountered or when the string ends.
 *
 * @param str The string to convert to a `long long` integer.
 *
 * @return The converted `long long` integer, or `ATOI_ERROR` if overflow occurs.
 *
 * @see ft_check_overflow
 * @see ATOI_ERROR
 * @ingroup number_conversions
 */
long long	ft_atoll(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		if (ft_check_overflow(num, *str, sign))
			return (ATOI_ERROR);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}
