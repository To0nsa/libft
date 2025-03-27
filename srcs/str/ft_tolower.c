/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:16:48 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:23:42 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @brief Converts a character to lowercase.
 *
 * This file contains the implementation of the `ft_tolower` function,
 * which takes an integer `c` (representing a character) and converts
 * it to lowercase if it is an uppercase letter. If `c` is already in
 * lowercase or not a letter, it is returned unchanged.
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Converts a character to lowercase.
 *
 * If the character `c` is an uppercase letter (between 'A' and 'Z'),
 * it is converted to its lowercase equivalent by adding the difference
 * between the ASCII values of 'a' and 'A'. If `c` is not an uppercase
 * letter, the function returns `c` unchanged.
 *
 * @param c The character to convert.
 *
 * @return The lowercase version of `c` if it is an uppercase letter;
 *         otherwise, returns `c` unchanged.
 *
 * @see ft_toupper
 * @ingroup string_utils
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}
