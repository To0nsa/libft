/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:00:26 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:51:33 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_bzero.c
 * @brief Sets memory bytes to zero.
 *
 * This file contains the implementation of `ft_bzero`, which clears
 * a block of memory by setting each byte to 0.
 *
 * @author nlouis
 * @date 2024/10/20
 * @ingroup memory_utils
 */
#include "libft.h"

/**
 * @brief Sets a block of memory to zero.
 *
 * This function sets the first @p n bytes of the memory area pointed to by
 * @p s to zero (bytes containing '\0'). It is commonly used to initialize
 * buffers or memory blocks to a known cleared state.
 *
 * @param s Pointer to the memory area to zero out.
 * @param n Number of bytes to set to zero.
 *
 * @return Nothing.
 *
 * @note This function behaves similarly to the standard `bzero` function.
 *       It is often used in combination with `malloc`, `calloc`, or custom
 *       memory allocators. `ft_memset` is preferred.
 *
 * @see ft_memset
 * @ingroup memory_utils
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
