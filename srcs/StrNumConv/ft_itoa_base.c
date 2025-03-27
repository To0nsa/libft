/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:01 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:37:29 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa_base.c
 * @brief Converts an unsigned long long integer to a string in a specified base.
 *
 * This file contains the implementation of `ft_itoa_base`, which converts an
 * unsigned long long integer to a string representation in a specified base.
 * It supports bases ranging from 2 to 16 and can produce either lowercase or
 * uppercase hexadecimal output based on the `uppercase` flag.
 *
 * @author nlouis
 * @date 2025/11/08
 * @ingroup number_conversions
 */
#include "libft.h"

/**
 * @brief Calculates the length of the number in the specified base.
 *
 * This helper function calculates how many digits are required to represent
 * a number `n` in the specified `base`. It repeatedly divides the number by
 * the base until it becomes 0, counting the number of iterations.
 *
 * @param n The number to calculate the length for.
 * @param base The base used for the calculation (between 2 and 16).
 *
 * @return The number of digits required to represent `n` in the given base.
 *
 * @see ft_itoa_base
 * @ingroup number_conversions
 */
static size_t	ft_baselen(unsigned long long n, int base)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

/**
 * @brief Converts an unsigned long long integer to a string in the specified base.
 *
 * This function takes an unsigned long long integer `n` and converts it to a
 * string representation in the specified `base` (between 2 and 16). The
 * `uppercase` flag controls whether hexadecimal letters are uppercase (`1`)
 * or lowercase (`0`). The function allocates memory for the resulting string
 * and returns a pointer to it.
 *
 * @param n The unsigned long long integer to convert.
 * @param base The base for conversion (between 2 and 16).
 * @param uppercase If `1`, hexadecimal letters will be uppercase; if `0`,
 *                  they will be lowercase.
 *
 * @return A string representing `n` in the given base, or `NULL` if an error
 *         occurs (e.g., invalid base or memory allocation failure).
 *
 * @see ft_baselen
 * @ingroup number_conversions
 */
char	*ft_itoa_base(unsigned long long n, int base, int uppercase)
{
	char				*digits;
	char				*str;
	size_t				len;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = ft_baselen(n, base);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = digits[n % base];
		n /= base;
	}
	return (str);
}
