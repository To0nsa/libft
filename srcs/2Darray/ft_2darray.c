/**
 * @file ft_2darray.c
 * @author Toonsa
 * @date 2025/04/05
 * @brief Utilities for dynamically allocated 2D integer arrays.
 *
 * @details
 * This file provides creation, duplication, printing, conversion, and
 * cleanup functions for working with dynamically allocated 2D arrays
 * of integers. These tools are useful in grid-based systems, map
 * parsing, and algorithmic simulations.
 *
 * @ingroup matrix_utils
 */

#include "libft.h"

/**
 * @brief Frees a 2D array of integers.
 *
 * @details
 * Releases memory allocated for a 2D array created with `ft_create_matrix`
 * or equivalent. Each row is freed individually, followed by the array of
 * pointers.
 *
 * @param matrix A pointer to the 2D array to free.
 * @param rows The number of rows in the array.
 *
 * @note Passing a NULL array is safe and does nothing.
 *
 * @see ft_create_matrix
 * @ingroup matrix_utils
 */
void ft_free_matrix(int** matrix, size_t rows)
{
	size_t i;

	if (!matrix)
		return;
	i = 0;
	while (i < rows)
		free(matrix[i++]);
	free(matrix);
}

/**
 * @brief Allocates a 2D array of integers initialized to 0.
 *
 * @details
 * This function allocates a 2D array with the specified number of rows and
 * columns, initializing all values to 0 using `ft_calloc`. If allocation
 * fails at any point, all previously allocated memory is freed and NULL is
 * returned.
 *
 * @param rows Number of rows in the 2D array.
 * @param cols Number of columns in the 2D array.
 * @return A pointer to the allocated 2D array, or NULL on failure.
 *
 * @note The returned array must be freed using `ft_free_matrix` to prevent
 * memory leaks.
 *
 * @see ft_free_matrix
 * @ingroup matrix_utils
 */
int** ft_create_matrix(size_t rows, size_t cols)
{
	int**  array;
	size_t i;

	array = (int**) ft_calloc(rows, sizeof(int*));
	if (!array)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = (int*) ft_calloc(cols, sizeof(int));
		if (!array[i])
		{
			ft_free_matrix(array, i);
			return (NULL);
		}
		i++;
	}
	return (array);
}

/**
 * @brief Creates a deep copy of a 2D array of integers.
 *
 * @details
 * Allocates and returns a new 2D array with the same dimensions and values as
 * the input. This function is useful when you need to work with a copy of the
 * original data without modifying it.
 *
 * @param matrix The original 2D array to copy.
 * @param rows The number of rows in the array.
 * @param cols The number of columns in the array.
 * @return A newly allocated deep copy of the array, or NULL on error.
 *
 * @note Uses `ft_create_matrix` to allocate the new array.
 *
 * @see ft_create_matrix
 * @ingroup matrix_utils
 */
int** ft_matrix_copy(int** matrix, size_t rows, size_t cols)
{
	int**  copy;
	size_t i;
	size_t j;

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

/**
 * @brief Prints a 2D array of integers to the standard output.
 *
 * @details
 * Uses `ft_printf` to print each row of the 2D array on a separate line.
 * Each integer is followed by a space. If any print call fails, returns -1.
 *
 * @param matrix A 2D array of integers.
 * @param rows The number of rows in the array.
 * @param cols The number of columns in the array.
 * @return 0 on success, or -1 if any write error occurs.
 *
 * @note If the array is NULL or any `ft_printf` fails, returns -1.
 *
 * @see ft_printf
 * @ingroup matrix_utils
 */
int ft_print_matrix(int** matrix, size_t rows, size_t cols)
{
	size_t i;
	size_t j;
	int    bytes_written;

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

/**
 * @brief Converts a NULL-terminated array of strings to a 2D integer array.
 *
 * @details
 * Each string in the array is interpreted as a row of digit characters.
 * Returns a 2D array of integers where each character is converted to
 * its numeric value (`'0'` → 0, `'1'` → 1, etc.).
 *
 * @param array A NULL-terminated array of strings (char **), where each
 *              string must contain only digit characters (0–9).
 * @return A newly allocated 2D integer array, or NULL on failure.
 *
 * @note Each string must have the same length. If allocation fails or
 *       the input is invalid, returns NULL.
 *
 * @see ft_create_matrix
 * @see ft_arraysize
 * @see ft_free_matrix
 * @ingroup matrix_utils
 */
int** ft_strarr_to_matrix(char** array)
{
	size_t rows;
	size_t cols;
	int**  matrix;
	size_t i;
	size_t j;

	rows   = ft_arraysize((void**) array);
	cols   = ft_strlen(array[0]);
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
