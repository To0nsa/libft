/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:33:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:15:57 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_create_matrix()
 * Allocates a 2D integer matrix with given dimensions.
 *
 * @rows: Number of rows to allocate.
 * @cols: Number of columns per row.
 *
 * Returns: A pointer to the newly allocated matrix,
 *          or NULL if allocation fails.
 *
 * Usage:
 * - Uses ft_calloc() to initialize all values to 0.
 * - On partial failure, previously allocated rows are freed
 *   using ft_free_matrix().
 * - The caller is responsible for freeing the matrix.
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
