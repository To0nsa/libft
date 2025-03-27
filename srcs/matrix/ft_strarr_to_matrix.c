/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_to_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:00:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:47:53 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "libft.h"

/**
 * @brief Converts a NULL-terminated array of strings to a 2D int matrix.
 *
 * This function interprets each string in the array as a row of digits.
 * It creates a matrix of integers where each character is converted to its
 * numeric value (`'0'` → 0, `'1'` → 1, etc.).
 *
 * @param array A NULL-terminated array of strings (char **), where each
 *              string must contain only digit characters (0–9).
 * 
 * @return A newly allocated 2D array of integers, or NULL on failure.
 *
 * @note Each string must be the same length. If the allocation fails or
 *       the input array is invalid, the function returns NULL.
 *
 * @see ft_create_matrix
 * @see ft_arraysize
 * @see ft_free_matrix
 * @ingroup matrix_utils
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
