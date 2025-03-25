/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_to_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:00:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:18:11 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strarr_to_matrix()
 * Converts an array of digit strings into a 2D integer matrix.
 *
 * @array: A NULL-terminated array of strings (each string = row of digits).
 *
 * Returns: A newly allocated integer matrix, or NULL on allocation failure.
 *
 * Usage:
 * - Each character in the string is converted with: char - '0'.
 * - Assumes all strings in the array are of equal length.
 * - Useful for parsing maps stored as digit strings ("00110").
 * - Caller is responsible for freeing the returned matrix.
 */
int	**ft_strarr_to_matrix(char **array)
{
	size_t	rows;
	size_t	cols;
	int		**matrix;
	size_t	i;
	size_t	j;

	rows = ft_arraysize((void **)array);
	cols = ft_strlen(array[0]);
	matrix = ft_create_matrix(rows, cols);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			matrix[i][j] = array[i][j] - '0';
			j++;
		}
		i++;
	}
	return (matrix);
}
