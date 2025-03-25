/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:10:01 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:56:35 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_baselen()
 * Calculates the number of digits needed to represent a number in a given base.
 *
 * @n: The number to evaluate.
 * @base: The base in which the number will be represented.
 *
 * Returns: The number of digits required.
 *
 * Notes:
 * - Returns 1 if n == 0 (since '0' is still one digit).
 * - Assumes base is valid and greater than 1.
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
 * ft_itoa_base()
 * Converts an unsigned long long number to a string in the given base.
 *
 * @n: The number to convert.
 * @base: The numeric base (between 2 and 16).
 * @uppercase: If non-zero, uses uppercase letters for bases > 10.
 *
 * Returns: A newly allocated string representing the number,
 *          or NULL if allocation fails or base is invalid.
 *
 * Notes:
 * - Supports bases from binary (2) to hexadecimal (16).
 * - Uses uppercase or lowercase digits based on @uppercase flag.
 * - Caller is responsible for freeing the returned string.
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
