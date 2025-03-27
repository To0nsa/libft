/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:18:47 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:45:56 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_free_matrix.c
 * @brief Frees a dynamically allocated 2D matrix of integers.
 *
 * This file contains the implementation of a utility function used to
 * free memory allocated for a two-dimensional matrix of integers.
 *
 * @author nlouis
 * @date 2025/02/08
 * @ingroup matrix_utils
 */
#include "libft.h"

/**
 * @brief Frees a 2D matrix of integers.
 *
 * This function releases the memory allocated for a matrix created with
 * `ft_create_matrix` or any similar allocation method. It iterates through
 * each row, frees it, and finally frees the array of row pointers.
 *
 * @param matrix A pointer to the matrix to free.
 * @param rows The number of rows in the matrix.
 *
 * @note Passing a NULL matrix is safe and does nothing.
 *
 * @see ft_create_matrix
 * @ingroup matrix_utils
 */
void	ft_free_matrix(int **matrix, size_t rows)
{
	size_t	i;

	if (!matrix)
		return ;
	i = 0;
	while (i < rows)
		free(matrix[i++]);
	free(matrix);
}
