/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 00:53:03 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 22:41:48 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_copy_strarray.c
 * @brief Deep copies a NULL-terminated string array.
 *
 * This file contains the implementation of `ft_copy_strarray`, which duplicates
 * a NULL-terminated array of strings.
 *
 * @author nlouis
 * @date 2025/01/03
 */
#include "libft.h"

/**
 * @brief Creates a deep copy of a NULL-terminated string array.
 *
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
 */
char	**ft_copy_strarray(char **array)
{
	size_t	size;
	size_t	i;
	char	**copy;

	if (!array)
		return (NULL);
	size = ft_arraysize((void **)array);
	copy = malloc((size + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = ft_strdup(array[i]);
		if (!copy[i])
		{
			ft_free_array((void **)copy);
			return (NULL);
		}
		i++;
	}
	copy[size] = NULL;
	return (copy);
}
