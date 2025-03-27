/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:57:16 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:26:18 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_cmp.c
 * @brief Comparison functions for qsort usage.
 *
 * Provides `int_cmp` and `double_cmp` for use with `ft_qsort`.
 *
 * These functions compare the values pointed to and return a result
 * suitable for use with generic sorting routines.
 *
 * @author nlouis
 * @date 2025/03/25
 * @ingroup sorting_utils
 * @see ft_qsort
 */
#include "libft.h"

/**
 * @brief Comparison function for two doubles.
 *
 * Compares the values pointed to by `a` and `b`.
 *
 * @param a Pointer to the first double.
 * @param b Pointer to the second double.
 * @return Negative if `a < b`, 0 if equal, positive if `a > b`.
 *
 * @see ft_qsort
 * @ingroup sorting_utils
 */
int double_cmp(const void *a, const void *b)
{
	double da = *(const double*)a;
	double db = *(const double*)b;

	return ((da > db) - (da < db));
}

/**
 * @brief Comparison function for two integers.
 *
 * Compares the values pointed to by `a` and `b`.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return Negative if `a < b`, 0 if equal, positive if `a > b`.
 *
 * @see ft_qsort
 * @ingroup sorting_utils
 */
int int_cmp(const void *a, const void *b)
{
	int int_a = *(const int *)a;
	int int_b = *(const int *)b;

	return ((int_a > int_b) - (int_a < int_b));
}
