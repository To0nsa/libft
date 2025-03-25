/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:18:26 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:25:33 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strcpy()
 * Copies a null-terminated string into another buffer.
 *
 * @dst: The destination buffer (must be large enough).
 * @src: The source string to copy.
 *
 * Returns: A pointer to the destination string @dst.
 *
 * Notes:
 * - Copies characters from @src to @dst, including the null terminator.
 * - Undefined behavior if @dst and @src overlap.
 * - Make sure @dst is allocated with enough space.
 */
char	*ft_strcpy(char *dst, const char *src)
{
	char	*ret;

	ret = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
