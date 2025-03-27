/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraysize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:39:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:35:33 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_arraysize.c
 * @brief Calculates the number of elements in a NULL-terminated array.
 *
 * This file contains the implementation of `ft_arraysire`, which counts the
 * number of elements in a NULL-terminated array of pointers.
 *
 * @author nlouis
 * @date 2025/02/08
 * @ingroup array_utils
 */
#include "libft.h"

/**
 * @brief Calculates the number of elements in a NULL-terminated array.
 *
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
size_t	ft_arraysize(void **array)
{
	size_t	size;

	if (!array)
		return (0);
	size = 0;
	while (array[size])
		size++;
	return (size);
}
