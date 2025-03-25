/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:49:08 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:15:13 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_matrix_copy()
 * Creates a deep copy of a 2D integer matrix.
 *
 * @matrix: The source matrix to copy.
 * @rows: Number of rows in the matrix.
 * @cols: Number of columns in the matrix.
 *
 * Returns: A newly allocated matrix with the same contents,
 *          or NULL if allocation fails or if matrix is NULL.
 *
 * Usage:
 * - Allocates memory using ft_create_matrix().
 * - Copies each element from the original matrix.
 * - Caller is responsible for freeing the returned matrix.
 */
int	**ft_matrix_copy(int **matrix, size_t rows, size_t cols)
{
	int		**copy;
	size_t	i;
	size_t	j;

	if (!matrix)
		return (NULL);
	copy = ft_create_matrix(rows, cols);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			copy[i][j] = matrix[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}
