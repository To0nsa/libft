/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:17:44 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 22:45:56 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putintarray.c
 * @brief Prints an array of integers to standard output.
 *
 * This file contains the implementation of `ft_putintarray`, a helper
 * function that displays a space-separated array of integers using
 * `ft_printf`.
 *
 * @author nlouis
 * @date 2024/12/13
 */
#include "libft.h"

/**
 * @brief Prints an integer array to standard output.
 *
 * Each integer is printed using `ft_printf` followed by a space,
 * except the last element. The function returns the total number of
 * characters printed.
 *
 * @param array A pointer to an array of integers.
 * @param size  The number of elements in the array.
 *
 * @return The total number of characters printed on success,
 *         or -1 if `ft_printf` fails.
 *
 * @note If `array` is NULL or size <= 0, the function returns 0.
 */
int	ft_putintarray(int *array, int size)
{
	int	total_bytes;
	int	bytes_written;
	int	i;

	if (!array || size <= 0)
		return (0);
	total_bytes = 0;
	i = 0;
	while (i < size)
	{
		bytes_written = ft_printf("%d", array[i]);
		if (bytes_written < 0)
			return (-1);
		total_bytes += bytes_written;
		if (i < size - 1)
		{
			bytes_written = ft_printf(" ");
			if (bytes_written < 0)
				return (-1);
			total_bytes += bytes_written;
		}
		i++;
	}
	return (total_bytes);
}
