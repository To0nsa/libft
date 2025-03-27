/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:49:08 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:43:32 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_matrix_copy.c
 * @brief Deep copies a 2D matrix of integers.
 *
 * This file implements a utility function to perform a deep copy of a 
 * dynamically allocated 2D integer matrix. The new matrix is independently
 * allocated and contains the same values as the original.
 *
 * @author nlouis
 * @date 2024
 * @ingroup matrix_utils
 */
#include "libft.h"

/**
 * @brief Creates a deep copy of a 2D matrix of integers.
 *
 * Allocates and returns a new matrix with the same dimensions and values as
 * the input. This function is useful when you need to work with a copy of the
 * original matrix without modifying it.
 *
 * @param matrix The original matrix to copy.
 * @param rows The number of rows in the matrix.
 * @param cols The number of columns in the matrix.
 * @return A newly allocated deep copy of the matrix, or NULL on error.
 *
 * @note Uses `ft_create_matrix` to allocate the new matrix.
 *
 * @see ft_create_matrix
 * @ingroup matrix_utils
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
