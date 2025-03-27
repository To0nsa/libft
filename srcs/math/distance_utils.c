/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:08:07 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:23:07 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file distance_utils.c
 * @brief Distance calculation functions for integer and float 2D points.
 *
 * This file provides functions to compute Manhattan and Euclidean distances
 * between 2D points, both in integer and floating-point precision.
 *
 * @author nlouis
 * @date 2025
 * @ingroup math_utils
 */
#include "libft.h"

/**
 * @brief Computes Manhattan distance between two integer points.
 *
 * Calculates the sum of the absolute differences in x and y coordinates.
 *
 * @param a The first point.
 * @param b The second point.
 * 
 * @return The Manhattan distance as an integer.
 * 
 * @ingroup math_utils
 */
int	ft_manhattan_dist_point(t_point a, t_point b)
{
	return (abs(a.x - b.x) + abs(a.y - b.y));
}

/**
 * @brief Computes Manhattan distance between two floating-point points.
 *
 * Calculates the sum of the absolute differences in x and y coordinates.
 *
 * @param a The first point (floating-point).
 * @param b The second point (floating-point).
 * 
 * @return The Manhattan distance as a double.
 * 
 * @ingroup math_utils
 */
double	ft_manhattan_dist_dpoint(t_dpoint a, t_dpoint b)
{
	return (fabs(a.x - b.x) + fabs(a.y - b.y));
}

/**
 * @brief Computes Euclidean distance between two integer points.
 *
 * Uses the Pythagorean theorem to compute the straight-line distance
 * between two points.
 *
 * @param a The first point.
 * @param b The second point.
 * 
 * @return The Euclidean distance as an integer (truncated).
 * 
 * @ingroup math_utils
 */
int	ft_euclidean_dist_point(t_point a, t_point b)
{
	return (sqrt(pow((double)a.x - (double)b.x, 2)
			+ pow((double)a.y - (double)b.y, 2)));
}

/**
 * @brief Computes Euclidean distance between two floating-point points.
 *
 * Uses the Pythagorean theorem to compute the straight-line distance
 * between two 2D points in double precision.
 *
 * @param a The first point (floating-point).
 * @param b The second point (floating-point).
 * 
 * @return The Euclidean distance as a double.
 * 
 * @ingroup math_utils
 */
double	ft_euclidean_dist_dpoint(t_dpoint a, t_dpoint b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}
