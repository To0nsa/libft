/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:18:47 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:16:35 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_free_matrix()
 * Frees a 2D integer matrix previously allocated.
 *
 * @matrix: The matrix to free.
 * @rows: Number of rows in the matrix.
 *
 * Returns: Nothing (void).
 *
 * Usage:
 * - Frees each row individually, then frees the matrix itself.
 * - Does nothing if matrix is NULL.
 * - Must match the number of rows passed to ft_create_matrix().
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
