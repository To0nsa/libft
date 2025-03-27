/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:06:15 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:57:27 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_swap.c
 * @brief Swaps two elements in memory.
 *
 * This file contains the implementation of the `ft_swap` function, which 
 * swaps the contents of two memory locations of a given size. The function 
 * uses a temporary buffer to perform the swap safely, ensuring that no data 
 * is overwritten in the process.
 *
 * @author nlouis
 * @date 2025/02/08
 * @ingroup utilities
 */
#include "libft.h"

/**
 * @brief Swaps the contents of two memory blocks.
 *
 * This function swaps the contents of two memory locations `a` and `b` of 
 * the specified size. The swap is performed using a temporary buffer to 
 * prevent data loss. It is essential to ensure that both pointers are 
 * non-NULL, and that the size is greater than zero for the function to work.
 * 
 * The function internally uses `ft_memcpy` to copy the contents between 
 * the two locations. After the swap, the temporary buffer is freed to avoid 
 * memory leaks.
 *
 * @param a A pointer to the first memory block.
 * @param b A pointer to the second memory block.
 * @param size The size of the memory blocks being swapped.
 *
 * @note If either `a`, `b`, or `size` is invalid (NULL or zero), the function 
 *       does nothing.
 *
 * @see ft_memcpy
 * @ingroup utilities
 */
void	ft_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	if (!a || !b || size == 0)
		return ;
	tmp = malloc(size);
	if (!tmp)
		return ;
	ft_memcpy(tmp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, tmp, size);
	free(tmp);
}
