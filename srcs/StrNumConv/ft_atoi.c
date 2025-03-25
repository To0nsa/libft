/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:00:10 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:36:30 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_check_overflow()
 * Checks if adding the next digit would cause an integer overflow.
 *
 * @num: Current accumulated number.
 * @digit: The next digit character to be added.
 * @sign: The current sign of the number (1 or -1).
 *
 * Returns: true if the next digit would cause an overflow, false otherwise.
 *
 * Notes:
 * - Handles both positive and negative overflows.
 * - Ensures safe conversion within 32-bit signed int limits.
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
 * ft_atoi()
 * Converts a string to an integer with overflow checking.
 *
 * @str: The input null-terminated string to convert.
 *
 * Returns: The converted integer value.
 *			Returns ATOI_ERROR (typically INT_MAX or INT_MIN) on overflow.
 *
 * Notes:
 * - Skips leading whitespaces (including \t, \n, \r, etc.).
 * - Handles optional '+' or '-' sign.
 * - Only processes consecutive digits after optional sign.
 * - Uses ft_check_overflow() to prevent undefined behavior on overflow.
 * - Returns result casted to (int), even though internally it uses long long.
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
