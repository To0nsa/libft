/**
 * @file ft_array.c
 * @author Toonsa
 * @date 2025/04/04
 * @brief Implementation of pointer and integer array utilities.
 *
 * This file is part of the libft project and implements helper functions
 * for working with dynamically allocated arrays:
 *
 * - `ft_arraysize`: counts elements in a NULL-terminated pointer array
 * - `ft_copy_strarray`: deep-copies a NULL-terminated string array
 * - `ft_free_array`: frees a NULL-terminated array
 * - `ft_free_array_size`: frees a pointer array of known size
 * - `ft_is_array_sorted`: checks if an integer array is sorted
 * - `ft_putintarray`: prints an integer array to standard output
 *
 * All functions are designed to be memory-safe and easy to use in
 * generic contexts such as CLI tools, parsers, or game engines.
 *
 * @ingroup array_utils
 */
#include "libft.h"

/**
 * @brief Calculates the number of elements in a NULL-terminated array.
 *
 * @details
 * This function iterates over a pointer array (usually a `char **` or
 * similar) and returns the number of non-NULL elements until it hits the
 * terminating NULL.
 *
 * @param array A NULL-terminated array of pointers.
 *
 * @return The number of elements before the NULL terminator.
 *         Returns 0 if the input array is NULL.
 *
 * @note This is commonly used to get the size of a string array like
 *       the result of `ft_split`, or an environment variable array.
 * @ingroup array_utils
 */
size_t ft_arraysize(void** array)
{
	size_t size;

	if (!array)
		return (0);
	size = 0;
	while (array[size])
		size++;
	return (size);
}

/**
 * @brief Creates a deep copy of a NULL-terminated string array.
 *
 * @details
 * Allocates a new array of strings and duplicates each string from the
 * input array using `ft_strdup`. If any allocation fails, all previously
 * allocated strings are freed and NULL is returned.
 *
 * @param array A NULL-terminated array of strings (char **).
 *
 * @return A newly allocated copy of the array with duplicated strings,
 *         or NULL if allocation fails or if the input array is NULL.
 *
 * @note The returned array must be freed using a function like
 *       `ft_free_array` to avoid memory leaks.
 *
 * @see ft_strdup
 * @see ft_free_array
 * @see ft_arraysize
 * @ingroup array_utils
 */
char** ft_copy_strarray(char** array)
{
	size_t size;
	size_t i;
	char** copy;

	if (!array)
		return (NULL);
	size = ft_arraysize((void**) array);
	copy = malloc((size + 1) * sizeof(char*));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = ft_strdup(array[i]);
		if (!copy[i])
		{
			ft_free_array((void**) copy);
			return (NULL);
		}
		i++;
	}
	copy[size] = NULL;
	return (copy);
}

/**
 * @brief Frees a NULL-terminated array of pointers.
 *
 * @details
 * Iterates through the array and frees each non-NULL element, then frees
 * the array itself.
 *
 * @param array A NULL-terminated array of dynamically allocated pointers.
 *
 * @note Safe to call with NULL. Use after functions like `ft_split` or
 *       `ft_copy_strarray` to release memory.
 * @ingroup array_utils
 */
void ft_free_array(void** array)
{
	size_t i;

	if (!array)
		return;
	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

/**
 * @brief Frees a pointer array of known size.
 *
 * @details
 * Frees each non-NULL element of the array up to the given size, then
 * frees the array itself.
 *
 * @param array An array of dynamically allocated pointers.
 * @param size The number of elements to free (not including a terminator).
 *
 * @note Useful when the array is not NULL-terminated or its size is known
 *       ahead of time.
 * @ingroup array_utils
 */
void ft_free_array_size(void** array, size_t size)
{
	size_t i;

	if (!array)
		return;
	i = 0;
	while (i < size)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

/**
 * @brief Checks if an integer array is sorted in ascending order.
 *
 * @param array The array to check.
 * @param size The number of elements in the array.
 * @return true if the array is sorted, false otherwise.
 *
 * @ingroup array_utils
 */
bool ft_is_array_sorted(const int* array, size_t size)
{
	if (!array || size <= 1)
		return true;
	for (size_t i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
			return false;
	}
	return true;
}

/**
 * @brief Prints an integer array to standard output.
 *
 * @details
 * Each integer is printed using `ft_printf` followed by a space,
 * except the last element. The function returns the total number of
 * characters printed.
 *
 * @param array A pointer to an array of integers.
 * @param size  The number of elements in the array.
 *
 * @return The total number of characters printed on success,
 *         or -1 if `ft_printf` fails.
 *
 * @note If `array` is NULL or size <= 0, the function returns 0.
 * @ingroup array_utils
 */
int ft_putintarray(int* array, int size)
{
	int total_bytes;
	int bytes_written;
	int i;

	if (!array || size <= 0)
		return (0);
	total_bytes = 0;
	i           = 0;
	while (i < size)
	{
		bytes_written = ft_printf("%d", array[i]);
		if (bytes_written < 0)
			return (-1);
		total_bytes += bytes_written;
		if (i < size - 1)
		{
			bytes_written = ft_printf(" ");
			if (bytes_written < 0)
				return (-1);
			total_bytes += bytes_written;
		}
		i++;
	}
	return (total_bytes);
}
