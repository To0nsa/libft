/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:07:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:13:27 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * get_vector_length()
 * Computes the length (magnitude) of a 2D vector.
 *
 * @vec: The input 2D vector.
 *
 * Returns: The length of the vector (sqrt(x² + y²)).
 */
double	get_vector_length(t_dpoint vec)
{
	double	length_squared;

	length_squared = vec.x * vec.x + vec.y * vec.y;
	return (sqrt(length_squared));
}

/**
 * divide_vector_by_scalar()
 * Divides a vector by a scalar value.
 *
 * @vec: The input 2D vector.
 * @scalar: The scalar to divide by.
 *
 * Returns: A new vector scaled by 1 / scalar.
 *
 * Note:
 * - Does not handle division by zero; caller must check.
 */
t_dpoint	divide_vector_by_scalar(t_dpoint vec, double scalar)
{
	t_dpoint	result;

	result.x = vec.x / scalar;
	result.y = vec.y / scalar;
	return (result);
}

/**
 * get_normalized_vector()
 * Returns the unit (normalized) form of a 2D vector.
 *
 * @vector: The input 2D vector.
 *
 * Returns: A unit vector in the same direction as input.
 *          Returns (0, 0) if the input vector is zero-length.
 *
 * Usage:
 * - Useful to keep direction but remove magnitude.
 */
t_dpoint	get_normalized_vector(t_dpoint vector)
{
	double		length;
	t_dpoint	unit_vector;

	length = get_vector_length(vector);
	if (length == 0)
		return ((t_dpoint){0, 0});
	unit_vector = divide_vector_by_scalar(vector, length);
	return (unit_vector);
}
