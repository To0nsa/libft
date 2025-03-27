/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:21:15 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:24:29 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file angle_utils.c
 * @brief Utility functions for angle conversions and normalization.
 *
 * This file contains helper functions to convert angles between radians
 * and degrees, and to normalize an angle within the [0, 2π) range.
 *
 * @author nlouis
 * @date 2025/03/23
 * @ingroup math_utils
 */
#include "libft.h"

/**
 * @brief Converts an angle from radians to degrees.
 *
 * Multiplies the given angle in radians by 180/π to obtain the value
 * in degrees.
 *
 * @param radians The angle in radians.
 * 
 * @return The angle in degrees.
 * 
 * @ingroup math_utils
 */
double	rad_to_deg(double radians)
{
	double	degrees;

	degrees = radians * (180.0 / M_PI);
	return (degrees);
}

/**
 * @brief Converts an angle from degrees to radians.
 *
 * Multiplies the given angle in degrees by π/180 to obtain the value
 * in radians.
 *
 * @param degrees The angle in degrees.
 * 
 * @return The angle in radians.
 * 
 * @ingroup math_utils
 */
double	deg_to_rad(double degrees)
{
	double	radians;

	radians = degrees * (M_PI / 180.0);
	return (radians);
}

/**
 * @brief Wraps an angle in radians to the range [0, 2π).
 *
 * This function normalizes an angle by adding or subtracting 2π until
 * it falls within the standard range for angles in radians.
 *
 * @param angle The angle in radians to normalize.
 * 
 * @return The normalized angle in the range [0, 2π).
 * 
 * @ingroup math_utils
 */
double	wrap_angle(double angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
