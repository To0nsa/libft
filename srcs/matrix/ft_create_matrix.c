/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:33:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:44:54 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_create_matrix.c
 * @brief Allocates a 2D matrix of integers.
 *
 * This file contains the implementation of a function to allocate a
 * two-dimensional array (matrix) of integers with given dimensions. Each
 * element is initialized to 0 using `ft_calloc`.
 *
 * @author nlouis
 * @date 2025/02/08
 * @ingroup matrix_utils
 */
#include "libft.h"

/**
 * @brief Allocates a 2D matrix of integers initialized to 0.
 *
 * This function allocates a matrix with the specified number of rows and
 * columns, initializing all values to 0 using `ft_calloc`. If allocation
 * fails at any point, all previously allocated memory is freed and NULL is
 * returned.
 *
 * @param rows Number of rows in the matrix.
 * @param cols Number of columns in the matrix.
 * @return A pointer to the allocated matrix, or NULL on failure.
 *
 * @note The returned matrix must be freed using `ft_free_matrix` to prevent
 * memory leaks.
 *
 * @see ft_free_matrix
 * @ingroup matrix_utils
 */
int	**ft_create_matrix(size_t rows, size_t cols)
{
	int		**matrix;
	size_t	i;

	matrix = (int **)ft_calloc(rows, sizeof(int *));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = (int *)ft_calloc(cols, sizeof(int));
		if (!matrix[i])
		{
			ft_free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}
