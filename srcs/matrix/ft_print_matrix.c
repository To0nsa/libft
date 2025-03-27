/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:59:23 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:46:59 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_print_matrix.c
 * @brief Prints a 2D integer matrix to the standard output.
 *
 * This file contains the implementation of a helper function used for
 * printing a matrix of integers with rows and columns. Each element is
 * printed with a space, and each row ends with a newline.
 *
 * @author nlouis
 * @date 2025/02/08
 * @ingroup matrix_utils
 */
#include "libft.h"

/**
 * @brief Prints a 2D matrix of integers to the standard output.
 *
 * This function uses `ft_printf` to display a matrix of integers,
 * printing each row on a separate line. Elements are separated by spaces.
 *
 * @param matrix A 2D array of integers.
 * @param rows The number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 * 
 * @return 0 on success, or -1 if any write error occurs.
 *
 * @note If the matrix is NULL or if any `ft_printf` call fails,
 *       the function returns -1.
 *
 * @see ft_printf
 * @ingroup matrix_utils
 */
int	ft_print_matrix(int **matrix, size_t rows, size_t cols)
{
	size_t	i;
	size_t	j;
	int		bytes_written;

	if (!matrix)
		return (-1);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			bytes_written = ft_printf("%d ", matrix[i][j]);
			if (bytes_written < 0)
				return (-1);
			j++;
		}
		bytes_written = ft_printf("\n");
		if (bytes_written < 0)
			return (-1);
		i++;
	}
	return (0);
}
