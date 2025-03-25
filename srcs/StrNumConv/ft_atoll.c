/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:00:10 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:37:23 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_check_overflow()
 * Checks if appending a digit would cause overflow in long long conversion.
 *
 * @num: The current accumulated number.
 * @digit: The next digit character to append.
 * @sign: The sign of the number (1 for positive, -1 for negative).
 *
 * Returns: true if the operation would overflow, false otherwise.
 *
 * Notes:
 * - Compares against LLONG_MAX and LLONG_MIN thresholds.
 * - Prevents undefined behavior during conversion in ft_atoll().
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
 * ft_atoll()
 * Converts a string to a long long integer with overflow checking.
 *
 * @str: The input null-terminated string to convert.
 *
 * Returns: The converted value as a long long,
 *          or ATOI_ERROR if overflow occurs.
 *
 * Notes:
 * - Skips leading whitespace characters (spaces, \t, \n, etc.).
 * - Handles optional '+' or '-' sign.
 * - Only processes numeric characters after the sign.
 * - Uses ft_check_overflow() to safely detect overflows.
 * - The return type is long long for extended range support.
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
