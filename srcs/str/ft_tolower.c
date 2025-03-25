/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:16:48 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:34:41 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_tolower()
 * Converts an uppercase letter to its lowercase equivalent.
 *
 * @c: The character to convert.
 *
 * Returns: The lowercase equivalent if @c is an uppercase letter,
 *			otherwise returns @c unchanged.
 *
 * Notes:
 * - Only affects characters in the range 'A' to 'Z'.
 * - Behavior is undefined for non-ASCII values.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}
