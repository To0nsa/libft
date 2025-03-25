/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:59:23 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:17:12 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_print_matrix()
 * Prints a 2D integer matrix to standard output using ft_printf.
 *
 * @matrix: The matrix to print.
 * @rows: Number of rows in the matrix.
 * @cols: Number of columns in the matrix.
 *
 * Returns: 0 on success, -1 if an error occurs (e.g., ft_printf failure).
 *
 * Usage:
 * - Prints each row on a new line, values separated by spaces.
 * - Returns -1 if matrix is NULL or ft_printf fails at any point.
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
