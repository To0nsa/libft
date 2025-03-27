/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_array_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:59:06 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/27 14:01:53 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_is_array_sorted.c
 * @brief Check whether an integer array is sorted in ascending order.
 *
 * This file contains the implementation of `ft_is_array_sorted`, a utility
 * function that verifies if a given integer array is sorted in non-decreasing
 * order. It is part of the array utility functions provided by libft.
 *
 * @author nlouis
 * @date 2025/03/27
 * @ingroup array
 */
#include "libft.h"

/**
 * @brief Checks if an integer array is sorted in ascending order.
 *
 * @param array The array to check.
 * @param size The number of elements in the array.
 * @return true if the array is sorted, false otherwise.
 * 
 * @ingroup array
 */
bool	ft_is_array_sorted(const int *array, size_t size)
{
	if (!array || size <= 1)
		return true;
	for (size_t i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
			return false;
	}
	return true;
}
