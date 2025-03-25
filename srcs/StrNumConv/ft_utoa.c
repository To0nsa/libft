/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:19:56 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:58:04 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_utoa()
 * Converts an unsigned long long to a decimal string.
 *
 * @n: The unsigned number to convert.
 *
 * Returns: A newly allocated null-terminated string representing @n,
 *          or NULL if allocation fails.
 *
 * Notes:
 * - Works for all values of unsigned long long, including 0.
 * - The caller is responsible for freeing the returned string.
 * - No sign is added since the value is always non-negative.
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
