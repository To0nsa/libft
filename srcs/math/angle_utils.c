/**
 * @file angle_utils.c
 * @author Toonsa
 * @date 05/04/2025
 * @brief Angle conversion and normalization utilities.
 *
 * @details
 * This file contains functions for converting angles between
 * radians and degrees, as well as normalizing angles into the
 * standard range [0, 2π). These utilities are useful for
 * graphics, geometry, and mathematical computations.
 *
 * @ingroup math_utils
 */

#include "libft.h"

/**
 * @brief Converts an angle from radians to degrees.
 *
 * @details
 * Multiplies the given angle in radians by 180/π to obtain
 * its value in degrees. This is commonly used when interfacing
 * with systems that expect degrees instead of radians.
 *
 * @param radians The angle in radians.
 * @return The angle in degrees.
 *
 * @ingroup math_utils
 */
double rad_to_deg(double radians)
{
	double degrees;

	degrees = radians * (180.0 / M_PI);
	return (degrees);
}

/**
 * @brief Converts an angle from degrees to radians.
 *
 * @details
 * Multiplies the given angle in degrees by π/180 to convert
 * it into radians. This is useful when dealing with trigonometric
 * functions that expect radians.
 *
 * @param degrees The angle in degrees.
 * @return The angle in radians.
 *
 * @ingroup math_utils
 */
double deg_to_rad(double degrees)
{
	double radians;

	radians = degrees * (M_PI / 180.0);
	return (radians);
}

/**
 * @brief Wraps an angle in radians to the range [0, 2π).
 *
 * @details
 * Normalizes the angle by continuously adding or subtracting
 * 2π until it fits within the standard interval [0, 2π). This
 * is essential when working with periodic functions or for
 * ensuring angular continuity in rendering and physics.
 *
 * @param angle The angle in radians to normalize.
 * @return The normalized angle in the range [0, 2π).
 *
 * @ingroup math_utils
 */
double wrap_angle(double angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}
