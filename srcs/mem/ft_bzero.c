/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:00:26 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:18:40 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_bzero()
 * Sets a block of memory to zero.
 *
 * @s: Pointer to the memory area to clear.
 * @n: Number of bytes to set to zero.
 *
 * Returns: Nothing (void).
 *
 * Usage:
 * - Equivalent to memset(s, 0, n), but implemented manually.
 * - Commonly used to initialize buffers or structures.
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
