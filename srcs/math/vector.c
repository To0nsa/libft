/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:07:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:34:42 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file vector.c
 * @brief Vector normalization and length operations.
 *
 * This file provides utility functions to compute the length of a vector,
 * normalize vectors, and divide a vector by a scalar.
 * 
 * @author nlouis
 * @date 2025/03/22
 * @ingroup math_utils
 */
#include "libft.h"

/**
 * @brief Computes the length (magnitude) of a 2D vector.
 *
 * Uses the Euclidean norm formula: sqrt(x^2 + y^2).
 *
 * @param vec A 2D vector.
 * 
 * @return The magnitude (length) of the vector.
 *
 * @ingroup math_utils
 */
double	get_vector_length(t_dpoint vec)
{
	double	length_squared;

	length_squared = vec.x * vec.x + vec.y * vec.y;
	return (sqrt(length_squared));
}

/**
 * @brief Divides a 2D vector by a scalar.
 *
 * Each component of the vector is divided by the scalar value.
 *
 * @param vec The original vector.
 * @param scalar The scalar to divide by.
 * 
 * @return A new vector with divided components.
 *
 * @warning Does not handle division by zero.
 *
 * @ingroup math_utils
 */
t_dpoint	divide_vector_by_scalar(t_dpoint vec, double scalar)
{
	t_dpoint	result;

	result.x = vec.x / scalar;
	result.y = vec.y / scalar;
	return (result);
}

/**
 * @brief Returns the normalized (unit length) vector.
 *
 * If the vector is zero-length, a (0, 0) vector is returned.
 *
 * @param vector The input vector to normalize.
 * 
 * @return A unit vector in the same direction.
 *
 * @see get_vector_length
 * @see divide_vector_by_scalar
 * @ingroup math_utils
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
