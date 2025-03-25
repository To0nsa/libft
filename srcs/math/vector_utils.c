/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:25:23 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:12:41 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * get_dot_product()
 * Computes the dot product of two 2D vectors.
 *
 * @vec1: First vector.
 * @vec2: Second vector.
 *
 * Returns: The scalar dot product of vec1 and vec2.
 *
 * Usage:
 * - Useful for projection, angle comparison, and direction similarity.
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
 * get_direction_vector()
 * Computes the direction vector from one point to another.
 *
 * @from: Starting point.
 * @to: Target point.
 *
 * Returns: A vector representing the direction from 'from' to 'to'.
 */
t_dpoint	get_direction_vector(t_dpoint from, t_dpoint to)
{
	t_dpoint	vector;

	vector.x = to.x - from.x;
	vector.y = to.y - from.y;
	return (vector);
}

/**
 * get_vector_angle()
 * Computes the angle (in radians) of a 2D vector from the X-axis.
 *
 * @vector: The input 2D vector.
 *
 * Returns: The angle in radians using atan2(y, x), in range [-π, π].
 */
double	get_vector_angle(t_dpoint vector)
{
	double	angle;

	angle = atan2(vector.y, vector.x);
	return (angle);
}

/**
 * get_vector_angle_between()
 * Computes the angle (in radians) between two 2D points.
 *
 * @from: Starting point.
 * @to: Target point.
 *
 * Returns: The angle in radians from 'from' to 'to'.
 *
 * Usage:
 * - Internally computes the direction vector and its angle.
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
 * get_unit_direction_vector()
 * Computes a normalized direction vector from one point to another.
 *
 * @from: Starting point.
 * @to: Target point.
 *
 * Returns: A unit vector pointing from 'from' to 'to'.
 *
 * Usage:
 * - Useful for direction-based movement or aiming.
 * - Calls get_normalized_vector() on the direction vector.
 */
t_dpoint	get_unit_direction_vector(t_dpoint from, t_dpoint to)
{
	t_dpoint	direction_vector;
	t_dpoint	unit_vector;

	direction_vector = get_direction_vector(from, to);
	unit_vector = get_normalized_vector(direction_vector);
	return (unit_vector);
}
