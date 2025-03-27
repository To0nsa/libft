/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:25:23 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:34:29 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file vector_analysis.c
 * @brief Vector-related utility functions for 2D calculations.
 *
 * This file provides operations related to direction vectors, angles, and
 * dot products, useful for geometry and physics simulations in 2D space.
 * 
 * @author nlouis
 * @date 2025/03/23
 * @ingroup math_utils
 */
#include "libft.h"

/**
 * @brief Computes the dot product of two 2D vectors.
 *
 * This is calculated as (x1 * x2 + y1 * y2).
 *
 * @param vec1 First 2D vector.
 * @param vec2 Second 2D vector.
 * 
 * @return The scalar dot product.
 *
 * @ingroup math_utils
 */
double	get_dot_product(t_dpoint vec1, t_dpoint vec2)
{
	double	product_x;
	double	product_y;
	double	dot_product;

	product_x = vec1.x * vec2.x;
	product_y = vec1.y * vec2.y;
	dot_product = product_x + product_y;
	return (dot_product);
}

/**
 * @brief Computes the vector pointing from one point to another.
 *
 * The resulting vector points from `from` to `to`.
 *
 * @param from Starting point.
 * @param to Target point.
 * 
 * @return A 2D vector representing the direction.
 *
 * @ingroup math_utils
 */
t_dpoint	get_direction_vector(t_dpoint from, t_dpoint to)
{
	t_dpoint	vector;

	vector.x = to.x - from.x;
	vector.y = to.y - from.y;
	return (vector);
}

/**
 * @brief Computes the angle of a 2D vector in radians.
 *
 * Uses `atan2(y, x)` to get the signed angle from the x-axis.
 *
 * @param vector The 2D vector.
 * 
 * @return The angle in radians.
 *
 * @ingroup math_utils
 */
double	get_vector_angle(t_dpoint vector)
{
	double	angle;

	angle = atan2(vector.y, vector.x);
	return (angle);
}

/**
 * @brief Computes the angle between two points as a direction vector.
 *
 * Computes the vector from `from` to `to` and returns its angle.
 *
 * @param from Starting point.
 * @param to Target point.
 * 
 * @return Angle in radians of the direction vector.
 *
 * @see get_direction_vector
 * @see get_vector_angle
 * @ingroup math_utils
 */
double	get_vector_angle_between(t_dpoint from, t_dpoint to)
{
	t_dpoint	direction_vector;
	double		angle;

	direction_vector = get_direction_vector(from, to);
	angle = get_vector_angle(direction_vector);
	return (angle);
}

/**
 * @brief Computes the normalized direction vector between two points.
 *
 * Converts the directional vector from `from` to `to` into a unit vector.
 *
 * @param from Starting point.
 * @param to Target point.
 * 
 * @return The unit direction vector.
 *
 * @see get_direction_vector
 * @see get_normalized_vector
 * @ingroup math_utils
 */
t_dpoint	get_unit_direction_vector(t_dpoint from, t_dpoint to)
{
	t_dpoint	direction_vector;
	t_dpoint	unit_vector;

	direction_vector = get_direction_vector(from, to);
	unit_vector = get_normalized_vector(direction_vector);
	return (unit_vector);
}
