/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:08:07 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:10:03 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_manhattan_dist_point()
 * Computes the Manhattan distance between two integer points.
 *
 * @a: First point (with integer coordinates).
 * @b: Second point (with integer coordinates).
 *
 * Returns: The Manhattan distance as an integer.
 *
 * Usage:
 * - Useful for grid-based movement (e.g., in tile-based games).
 */
int	ft_manhattan_dist_point(t_point a, t_point b)
{
	return (abs(a.x - b.x) + abs(a.y - b.y));
}

/**
 * ft_manhattan_dist_dpoint()
 * Computes the Manhattan distance between two double points.
 *
 * @a: First point (with double coordinates).
 * @b: Second point (with double coordinates).
 *
 * Returns: The Manhattan distance as a double.
 */
double	ft_manhattan_dist_dpoint(t_dpoint a, t_dpoint b)
{
	return (fabs(a.x - b.x) + fabs(a.y - b.y));
}

/**
 * ft_euclidean_dist_point()
 * Computes the Euclidean distance between two integer points.
 *
 * @a: First point (with integer coordinates).
 * @b: Second point (with integer coordinates).
 *
 * Returns: The Euclidean distance as an integer (rounded).
 *
 * Usage:
 * - Returns the straight-line distance between two points.
 * - Casts to double for accuracy, but final result is int.
 */
int	ft_euclidean_dist_point(t_point a, t_point b)
{
	return (sqrt(pow((double)a.x - (double)b.x, 2)
			+ pow((double)a.y - (double)b.y, 2)));
}

/**
 * ft_euclidean_dist_dpoint()
 * Computes the Euclidean distance between two double points.
 *
 * @a: First point (with double coordinates).
 * @b: Second point (with double coordinates).
 *
 * Returns: The Euclidean distance as a double.
 */
double	ft_euclidean_dist_dpoint(t_dpoint a, t_dpoint b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}
