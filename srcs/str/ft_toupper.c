/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:16:37 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:35:24 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_toupper()
 * Converts a lowercase letter to its uppercase equivalent.
 *
 * @c: The character to convert.
 *
 * Returns: The uppercase equivalent if @c is a lowercase letter,
 *          otherwise returns @c unchanged.
 *
 * Notes:
 * - Only affects characters in the range 'a' to 'z'.
 * - Behavior is undefined for non-ASCII values.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}
