/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:57:16 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 11:01:08 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * double_cmp()
 * Comparator function for sorting an array of doubles.
 *
 * @a: Pointer to the first double.
 * @b: Pointer to the second double.
 *
 * Returns:
 *	- Negative value if *a < *b
 *	- Zero if *a == *b
 *	- Positive value if *a > *b
 *
 * Note:
 *	Works correctly with all double values except NaN.
 */
int double_cmp(const void *a, const void *b)
{
	double da = *(const double*)a;
	double db = *(const double*)b;

	return ((da > db) - (da < db));
}

/**
 * int_cmp()
 * Comparator function for sorting an array of integers.
 *
 * @a: Pointer to the first int.
 * @b: Pointer to the second int.
 *
 * Returns:
 *   - Negative value if *a < *b
 *   - Zero if *a == *b
 *   - Positive value if *a > *b
 *
 * Note:
 * 	This form is safe and avoids overflow that can happen with direct subtraction.
 */
int int_cmp(const void *a, const void *b)
{
	int int_a = *(const int *)a;
	int int_b = *(const int *)b;

	return ((int_a > int_b) - (int_a < int_b));
}
