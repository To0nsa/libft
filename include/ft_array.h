/**
 * @file ft_array.h
 * @author Toonsa
 * @date 2025/04/04
 * @brief Utility functions for handling pointer and integer arrays.
 *
 * @details
 * This header is part of the libft project and provides a collection
 * of helper functions to operate on generic arrays, particularly:
 *
 * - NULL-terminated arrays (e.g., `char **`)
 * - Dynamically allocated pointer arrays
 * - Integer arrays
 *
 * It includes tools for:
 * - Getting the size of a pointer array
 * - Copying and freeing arrays
 * - Checking sorting order
 * - Printing integer arrays for debugging
 *
 * @note All functions are written to be memory-safe and are suitable for use
 * in projects that require manipulation of dynamically allocated array data.
 *
 *
 * @ingroup array_utils
 */
#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>	// size_t
# include <stdbool.h>	// bool
# include <stdlib.h>	// malloc, free

/**
 * @defgroup array_utils Array Utilities
 * @brief Functions for working with pointer arrays (char**, void**, etc.).
 *
 * @details
 * Includes functions for:
 * - Measuring array size
 * - Copying or freeing arrays
 * - Printing and checking sort
 * 
 * This group includes:
 * @see ft_arraysize
 * @see ft_copy_strarray
 * @see ft_free_array
 * @see ft_free_array_size
 * @see ft_is_array_sorted
 * @see ft_putintarray
 * 
 * @{
 */

/**
 * @brief Returns the number of elements in a NULL-terminated array.
 *
 * @param array The array of pointers (NULL-terminated).
 * @return The number of elements in the array.
 */
size_t		ft_arraysize(void **array);

/**
 * @brief Creates a deep copy of a NULL-terminated string array.
 *
 * @param array The original string array to copy.
 * @return A newly allocated copy of the array, or NULL on failure.
 */
char		**ft_copy_strarray(char **array);

/**
 * @brief Frees a NULL-terminated array.
 *
 * @param array The array to free.
 */
void		ft_free_array(void **array);

/**
 * @brief Frees an array of pointers with a known size.
 *
 * @param array The array to free.
 * @param size Number of elements in the array.
 */
void		ft_free_array_size(void **array, size_t size);

/**
 * @brief Prints an array of integers to standard output.
 *
 * @param array The array to print.
 * @param size Number of elements.
 * @return The number of characters printed, or -1 on error.
 */
int			ft_putintarray(int *array, int size);

/**
 * @brief Checks if an array of integers is sorted in ascending order.
 *
 * @param array The array to check.
 * @param size Number of elements in the array.
 * @return true if sorted, false otherwise.
 */
bool		ft_is_array_sorted(const int *array, size_t size);

/** @} */ // end of array_utils group

#endif
