/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:22:16 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:11:20 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * clamp()
 * Clamps a value between a minimum and maximum limit.
 *
 * @value: The input value to clamp.
 * @min: The lower bound.
 * @max: The upper bound.
 *
 * Returns: The value, limited to the [min, max] range.
 *
 * Usage:
 * - Useful to avoid exceeding valid ranges (e.g., screen coords, colors).
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
 * get_fractional_part()
 * Extracts the decimal (fractional) part of a floating-point number.
 *
 * @value: The input floating-point number.
 *
 * Returns: The fractional part (value - floor(value)).
 *
 * Example:
 * - Input:  4.75  → Output: 0.75
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
 * wrap_in_range()
 * Wraps a value within the range [0, range).
 *
 * @value: The value to wrap.
 * @range: The range limit (must be positive).
 *
 * Returns: The value wrapped within [0, range).
 *
 * Usage:
 * - Useful for cyclic values (texture offsets, animation frames).
 */
double	wrap_in_range(double value, double range)
{
	if (value < 0.0)
		value += range;
	else if (value >= range)
		value -= range;
	return (value);
}
