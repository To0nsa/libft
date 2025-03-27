/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:45:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:04:16 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_striteri.c
 * @brief Applies a function to each character of a string with its index.
 *
 * This file contains the implementation of `ft_striteri`, which allows 
 * applying a function to each character of a string along with its index.
 * The string is modified in place.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Applies a function to each character of a string, passing its index.
 *
 * Iterates over the string `s` and applies the function `f` to each character.
 * The function receives the index of the character and a pointer to it, 
 * allowing in-place modification.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 *
 * @note If either `s` or `f` is NULL, the function does nothing.
 *
 * @ingroup string_utils
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
