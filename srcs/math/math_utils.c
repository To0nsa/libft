/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:22:16 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:26:36 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file math_utils.c
 * @brief Miscellaneous mathematical utility functions.
 *
 * This file contains helper functions for numerical operations such as
 * clamping values, extracting the fractional part of a number, and wrapping
 * a value within a specific range.
 * 
 * @author nlouis
 * @date 2025/03/23
 * @ingroup math_utils
 */
#include "libft.h"

/**
 * @brief Clamps a value between a minimum and maximum.
 *
 * If the value is less than `min`, returns `min`. If greater than `max`,
 * returns `max`. Otherwise, returns the original value.
 *
 * @param value The input value to clamp.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 * 
 * @return The clamped value.
 *
 * @ingroup math_utils
 */
double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

/**
 * @brief Gets the fractional part of a floating-point number.
 *
 * This function returns the decimal part of the input, discarding the
 * integer part.
 *
 * @param value The input value.
 * 
 * @return The fractional part of the input (value - floor(value)).
 *
 * @ingroup math_utils
 */
double	get_fractional_part(double value)
{
	double	integer_part;
	double	decimal_part;

	integer_part = floor(value);
	decimal_part = value - integer_part;
	return (decimal_part);
}

/**
 * @brief Wraps a value within the range [0, range).
 *
 * If the value is negative, it is increased by the range. If it exceeds or
 * equals the range, it is reduced by the range.
 *
 * @param value The value to wrap.
 * @param range The range in which to wrap the value.
 * 
 * @return A wrapped value within [0, range).
 *
 * @ingroup math_utils
 */
double	wrap_in_range(double value, double range)
{
	if (value < 0.0)
		value += range;
	else if (value >= range)
		value -= range;
	return (value);
}
