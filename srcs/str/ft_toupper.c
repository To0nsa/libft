/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:16:37 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:23:51 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_toupper.c
 * @brief Converts a character to uppercase.
 *
 * This file contains the implementation of the `ft_toupper` function,
 * which takes an integer `c` (representing a character) and converts
 * it to uppercase if it is a lowercase letter. If `c` is already in
 * uppercase or not a letter, it is returned unchanged.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Converts a character to uppercase.
 *
 * If the character `c` is a lowercase letter (between 'a' and 'z'),
 * it is converted to its uppercase equivalent by subtracting the 
 * difference between the ASCII values of 'a' and 'A'. If `c` is not
 * a lowercase letter, the function returns `c` unchanged.
 *
 * @param c The character to convert.
 *
 * @return The uppercase version of `c` if it is a lowercase letter;
 *         otherwise, returns `c` unchanged.
 *
 * @see ft_tolower
 * @ingroup char_check
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}
