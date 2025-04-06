/**
 * @file distance_utils.c
 * @author Toonsa
 * @date 2025-04-05
 * @brief Distance computation utilities for 2D points.
 *
 * @details
 * This file provides functions for computing distances between 2D
 * points, including both Manhattan and Euclidean distances. It supports
 * both integer-based (`t_point`) and double-precision (`t_dpoint`) points.
 *
 * These functions are useful in grid-based algorithms, AI navigation,
 * and geometric analysis.
 *
 * @ingroup math_utils
 */

#include "libft.h"

/**
 * @brief Computes Manhattan distance between two integer points.
 *
 * @details
 * Calculates the sum of the absolute differences in the x and y
 * coordinates. This is often used in grid-based pathfinding like
 * A* or taxicab geometry.
 *
 * @param a The first point.
 * @param b The second point.
 * @return The Manhattan distance as an integer.
 *
 * @ingroup math_utils
 */
int ft_manhattan_dist_point(t_point a, t_point b)
{
	return (abs(a.x - b.x) + abs(a.y - b.y));
}

/**
 * @brief Computes Manhattan distance between two floating-point points.
 *
 * @details
 * Calculates the Manhattan distance using floating-point coordinates.
 * This version is useful for precise 2D simulations and smooth position
 * interpolation where integer coordinates are insufficient.
 *
 * @param a The first point (floating-point).
 * @param b The second point (floating-point).
 * @return The Manhattan distance as a double.
 *
 * @ingroup math_utils
 */
double ft_manhattan_dist_dpoint(t_dpoint a, t_dpoint b)
{
	return (fabs(a.x - b.x) + fabs(a.y - b.y));
}

/**
 * @brief Computes Euclidean distance between two integer points.
 *
 * @details
 * Applies the Pythagorean theorem to compute the straight-line
 * distance between two 2D integer points. Internally casts to `double`
 * to perform accurate calculations. The final result is truncated
 * to an integer.
 *
 * @param a The first point.
 * @param b The second point.
 * @return The Euclidean distance as an integer (truncated).
 *
 * @ingroup math_utils
 */
int ft_euclidean_dist_point(t_point a, t_point b)
{
	return (sqrt(pow((double) a.x - (double) b.x, 2) +
	             pow((double) a.y - (double) b.y, 2)));
}

/**
 * @brief Computes Euclidean distance between two floating-point points.
 *
 * @details
 * Uses the Pythagorean theorem to compute the straight-line distance
 * between two points represented with `t_dpoint`. This is useful in
 * precise geometric contexts such as physics or rendering systems.
 *
 * @param a The first point (floating-point).
 * @param b The second point (floating-point).
 * @return The Euclidean distance as a double.
 *
 * @ingroup math_utils
 */
double ft_euclidean_dist_dpoint(t_dpoint a, t_dpoint b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}
