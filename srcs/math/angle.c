/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:21:15 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:04:45 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * rad_to_deg()
 * Converts an angle from radians to degrees.
 *
 * @radians: The angle in radians.
 *
 * Returns: The angle converted to degrees.
 */

double	rad_to_deg(double radians)
{
	double	degrees;

	degrees = radians * (180.0 / M_PI);
	return (degrees);
}

/**
 * deg_to_rad()
 * Converts an angle from degrees to radians.
 *
 * @degrees: The angle in degrees.
 *
 * Returns: The angle converted to radians.
 */

double	deg_to_rad(double degrees)
{
	double	radians;

	radians = degrees * (M_PI / 180.0);
	return (radians);
}

/**
 * wrap_angle()
 * Wraps an angle to the range [0, 2π).
 *
 * @angle: The angle in radians.
 *
 * Returns: The equivalent angle within the [0, 2π) range.
 */

double	wrap_angle(double angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
