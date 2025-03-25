/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:45:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:26:26 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_striteri()
 * Applies a function to each character of a string with its index.
 *
 * @s: The string to iterate over.
 * @f: The function to apply, taking the index and a pointer to the char.
 *
 * Returns: Nothing (void).
 *
 * Notes:
 * - The function @f can modify the characters in-place.
 * - Iteration stops at the null terminator.
 * - Does nothing if @s or @f is NULL.
 *
 * Example:
 * - Can be used to transform a string to uppercase, lowercase, etc.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
