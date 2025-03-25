/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:06:15 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 10:01:05 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_swap()
 * Swaps the contents of two memory areas of a given size.
 *
 * @a: Pointer to the first memory area.
 * @b: Pointer to the second memory area.
 * @size: Number of bytes to swap.
 *
 * Returns: Nothing (void).
 *
 * Notes:
 * - Uses a temporary buffer and ft_memcpy() for safe memory copying.
 * - Does nothing if a or b is NULL, or if size is 0.
 * - Caller must ensure that both memory areas are at least @size bytes.
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
