/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:55:29 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:36:50 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_is_valid_integer.c
 * @brief Validates whether a string represents a valid `long long` integer.
 *
 * This file provides a utility function to check whether a given string is a
 * valid integer representation that fits within the `long long` range.
 * The function supports optional '+' or '-' signs.
 *
 * @author nlouis
 * @date 2025/01/31
 * @ingroup char_check
 */
#include "libft.h"

/**
 * @brief Checks if a numeric string fits within the `long long` range.
 *
 * This helper function verifies whether the numeric value represented by
 * the string is within the bounds of a signed `long long`, taking into
 * account the sign.
 *
 * @param str The numeric string to check (without sign).
 * @param negative Indicates whether the number is negative.
 *
 * @return true if the string fits within `long long` bounds, false otherwise.
 * 
 * @see ft_isdigit
 * @ingroup char_check
 */
static bool	is_in_longlong_range(const char *str, bool negative)
{
	unsigned long long	limit;
	unsigned long long	sum;
	int					digit;

	if (negative)
		limit = (unsigned long long)LLONG_MAX + 1ULL;
	else
		limit = (unsigned long long)LLONG_MAX;
	sum = 0;
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (false);
		digit = *str - '0';
		if (sum > (limit - digit) / 10ULL)
			return (false);
		sum = sum * 10ULL + digit;
		str++;
	}
	return (true);
}

/**
 * @brief Validates if a string represents a valid `long long` integer.
 *
 * This function checks whether the input string is a valid numeric
 * representation (optional sign, digits only) that fits in a `long long`.
 *
 * @param str The input string to validate.
 *
 * @return true if the string is valid, false otherwise.
 * 
 * @see is_in_longlong_range
 * @ingroup char_check
 */
bool	ft_is_valid_integer(const char *str)
{
	bool	negative;

	if (!str || !*str)
		return (false);
	negative = false;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = true;
		str++;
	}
	if (!*str)
		return (false);
	if (!is_in_longlong_range(str, negative))
		return (false);
	return (true);
}
