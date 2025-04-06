/**
 * @file ft_2darray.h
 * @author Toonsa
 * @date 05/04/2025
 * @brief 2D integer array utilities.
 *
 * @details
 * This header provides functions for handling dynamically allocated
 * 2D integer arrays. Operations include creation, duplication,
 * conversion from string arrays, printing, and memory cleanup.
 *
 * These utilities are especially useful in grid-based systems such as
 * map parsing, cellular automata, or algorithmic simulations.
 *
 * @ingroup matrix_utils
 */

#ifndef FT_2DARRAY_H
#define FT_2DARRAY_H

/**
 * @defgroup matrix_utils 2D Array Utilities
 * @brief Utilities for working with 2D integer arrays.
 *
 * @details
 * These functions are designed to create, copy, convert, print, and free
 * dynamically allocated 2D integer arrays (grids).
 *
 * Useful for grid-based applications such as game maps or algorithmic tasks.
 *
 * This group includes:
 * - @ref ft_matrix_copy
 * - @ref ft_create_matrix
 * - @ref ft_free_matrix
 * - @ref ft_print_matrix
 * - @ref ft_strarr_to_matrix
 * @{
 */

int** ft_matrix_copy(int** array, size_t rows, size_t cols);
int** ft_create_matrix(size_t rows, size_t cols);
void  ft_free_matrix(int** array, size_t rows);
int   ft_print_matrix(int** array, size_t rows, size_t cols);
int** ft_strarr_to_matrix(char** str_array);

/** @} */ // end of matrix_utils group

#endif
