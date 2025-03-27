/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:00:10 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:31:47 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @brief Converts a string to a long long integer.
 *
 * This file contains the implementation of `ft_atoi`, which converts
 * a string representation of a number to a `long long` integer, handling
 * possible overflows and whitespaces. The function accounts for optional
 * leading signs (`+` or `-`) and any number of leading spaces or tab characters.
 * It also checks for overflow conditions, returning a predefined error constant
 * when the number exceeds the limits of a valid `long long` integer.
 *
 * @author nlouis
 * @date 2024/10/20
 * @ingroup number_conversions
 */
#include "libft.h"

/**
 * @brief Checks for overflow when converting a string to a long long integer.
 *
 * This function checks whether the result of the ongoing conversion would
 * overflow the `long long` integer range, either for positive or negative values.
 *
 * @param num The current number being built during conversion.
 * @param digit The current digit being processed in the string.
 * @param sign The sign of the number being processed: 1 for positive, -1 for negative.
 *
 * @return True if overflow would occur, false otherwise.
 *
 * @see ft_atoi
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
 * @brief Converts a string to a long long integer.
 *
 * This function converts a string to a `long long` integer, considering
 * optional leading signs (`+` or `-`) and ignoring leading whitespace characters.
 * It checks for valid digits and stops parsing when a non-digit character is encountered.
 * The function also handles potential overflows and returns a predefined error constant
 * if the result exceeds the `long long` integer limits.
 *
 * @param str The string to convert.
 *
 * @return The converted `long long` integer, or a predefined error constant if overflow occurs.
 *
 * @see ft_check_overflow
 * @see ATOI_ERROR
 * @ingroup number_conversions
 */
long long	ft_atoi(const char *str)
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
	return ((int)num * sign);
}
