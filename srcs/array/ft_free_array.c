/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:58:55 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 22:45:00 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_free_array.c
 * @brief Functions to free dynamically allocated arrays of pointers.
 *
 * This file provides utility functions to safely deallocate memory used by
 * NULL-terminated or sized arrays of pointers (such as string arrays).
 *
 * Includes:
 * - `ft_free_array` for NULL-terminated arrays
 * - `ft_free_array_size` for arrays with a known length
 *
 * @author nlouis
 * @date 2024/11/21
 */
#include "libft.h"

/**
 * @brief Frees a NULL-terminated array of pointers.
 *
 * Iterates through the array and frees each non-NULL element, then frees
 * the array itself.
 *
 * @param array A NULL-terminated array of dynamically allocated pointers.
 *
 * @note Safe to call with NULL. Use after functions like `ft_split` or
 *       `ft_copy_strarray` to release memory.
 */
void	ft_free_array(void **array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

/**
 * @brief Frees a pointer array of known size.
 *
 * Frees each non-NULL element of the array up to the given size, then
 * frees the array itself.
 *
 * @param array An array of dynamically allocated pointers.
 * @param size The number of elements to free (not including a terminator).
 *
 * @note Useful when the array is not NULL-terminated or its size is known
 *       ahead of time.
 */
void	ft_free_array_size(void **array, size_t size)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (i < size)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}
