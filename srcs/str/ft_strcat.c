/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:24:25 by riamaev           #+#    #+#             */
/*   Updated: 2025/03/25 09:23:54 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_strcat()
 * Concatenates the src string to the end of dest.
 *
 * @dest: The destination string (must be large enough to hold the result).
 * @src: The source string to append.
 *
 * Returns: A pointer to the resulting string @dest.
 *
 * Usage:
 * - Appends src to the end of dest, including the null terminator.
 * - Assumes dest is properly null-terminated and has enough space.
 * - Behavior is undefined if dest overlaps with src.
 */
char	*ft_strcat(char *dest, const char *src)
{
	char	*dest_ptr;

	dest_ptr = dest;
	while (*dest_ptr != '\0')
		dest_ptr++;
	while (*src != '\0')
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}
	*dest_ptr = '\0';
	return (dest);
}
