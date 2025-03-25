/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:46:47 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:29:31 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strlen()
 * Calculates the length of a null-terminated string.
 *
 * @str: The input string.
 *
 * Returns: The number of characters in the string,
 *			excluding the null terminator.
 *
 * Notes:
 * - Equivalent to strlen() in the standard library.
 * - Behavior is undefined if @str is NULL.
 */

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
