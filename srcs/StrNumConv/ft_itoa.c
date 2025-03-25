/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:38:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:57:17 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_nlen()
 * Calculates the number of characters needed to represent a number in base 10.
 *
 * @n: The number to evaluate.
 *
 * Returns: The number of characters, including '-' if the number is negative.
 *
 * Notes:
 * - Returns 1 for n == 0 (one digit).
 * - Handles negative numbers by counting the minus sign.
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
 * ft_itoa()
 * Converts a signed long long integer to a string representation.
 *
 * @n: The number to convert.
 *
 * Returns: A newly allocated string representing the number,
 *          or NULL if allocation fails.
 *
 * Notes:
 * - Handles negative numbers and returns a string with '-' prefix.
 * - Uses unsigned long long internally to avoid overflow on -LLONG_MIN.
 * - The returned string is null-terminated.
 * - Caller is responsible for freeing the result.
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
