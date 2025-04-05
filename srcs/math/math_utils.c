/**
 * @file math_utils.c
 * @author Toonsa
 * @date 2025-04-05
 * @brief Utility math functions for floating-point operations.
 *
 * @details
 * This file provides generic math utilities such as clamping values,
 * extracting fractional parts, and wrapping values within ranges.
 * These functions are commonly used in mathematical computations,
 * rendering systems, and game development logic.
 * 
 * @ingroup math_utils
 */

 #include "libft.h"

 /**
  * @brief Clamps a value between a minimum and maximum.
  * 
  * @details
  * Ensures that the returned value lies within the interval
  * [`min`, `max`]. If the input is below `min`, returns `min`.
  * If above `max`, returns `max`. Otherwise, returns `value`.
  *
  * @param value The input value to clamp.
  * @param min The minimum allowed value.
  * @param max The maximum allowed value.
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
  * @details
  * Returns the part of the input after the decimal point by
  * subtracting the floored value from the original. This is
  * useful in periodic functions or graphical effects.
  *
  * @param value The input value.
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
  * @details
  * Normalizes a value to be within the bounds of `[0, range)`. If the
  * value is below 0, adds the range. If it's greater than or equal
  * to the range, subtracts the range.
  * 
  * This is commonly used in cyclic systems like angles or timers.
  *
  * @param value The value to wrap.
  * @param range The range in which to wrap the value.
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
 