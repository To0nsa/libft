/**
 * @file vector.c
 * @author nlouis
 * @date 2025-04-05
 * @brief 2D vector utility functions for geometry and direction.
 *
 * @details
 * This file provides utilities for 2D vector math using `t_dpoint`
 * structures. Functions include vector length, normalization, 
 * direction, dot product, and angle computation.
 * 
 * These operations are useful for physics, rendering, AI movement,
 * and angle-based calculations in game engines.
 *
 * @ingroup math_utils
 */

 #include "libft.h"

 /**
  * @brief Computes the length (magnitude) of a 2D vector.
  * 
  * @details
  * Uses the Euclidean norm formula: `sqrt(x² + y²)` to compute the
  * vector's magnitude. This is commonly used for normalization,
  * distance evaluation, and vector-based physics.
  *
  * @param vec A 2D vector.
  * @return The magnitude (length) of the vector.
  *
  * @ingroup math_utils
  */
 double	get_vector_length(t_dpoint vec)
 {
	 double	length_squared;
 
	 length_squared = vec.x * vec.x + vec.y * vec.y;
	 return (sqrt(length_squared));
 }
 
 /**
  * @brief Divides a 2D vector by a scalar.
  * 
  * @details
  * Returns a new vector with each component divided by the given scalar.
  * This is often used for vector normalization or scaling down.
  *
  * @param vec The original vector.
  * @param scalar The scalar to divide by.
  * @return A new vector with divided components.
  *
  * @warning Does not handle division by zero.
  *
  * @ingroup math_utils
  */
 t_dpoint	divide_vector_by_scalar(t_dpoint vec, double scalar)
 {
	 t_dpoint	result;
 
	 result.x = vec.x / scalar;
	 result.y = vec.y / scalar;
	 return (result);
 }
 
 /**
  * @brief Returns the normalized (unit length) vector.
  * 
  * @details
  * Produces a vector with length 1 pointing in the same direction
  * as the input. If the input is zero-length, returns (0, 0).
  *
  * @param vector The input vector to normalize.
  * @return A unit vector in the same direction.
  *
  * @see get_vector_length
  * @see divide_vector_by_scalar
  * @ingroup math_utils
  */
 t_dpoint	get_normalized_vector(t_dpoint vector)
 {
	 double		length;
	 t_dpoint	unit_vector;
 
	 length = get_vector_length(vector);
	 if (length == 0)
		 return ((t_dpoint){0, 0});
	 unit_vector = divide_vector_by_scalar(vector, length);
	 return (unit_vector);
 }
 
 /**
  * @brief Computes the dot product of two 2D vectors.
  * 
  * @details
  * Calculates the scalar dot product as `(x1 * x2 + y1 * y2)`.
  * This is useful for projections, angle comparisons, and
  * detecting perpendicular vectors.
  *
  * @param vec1 First 2D vector.
  * @param vec2 Second 2D vector.
  * @return The scalar dot product.
  *
  * @ingroup math_utils
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
  * @brief Computes the vector pointing from one point to another.
  * 
  * @details
  * Returns the vector representing the displacement from `from`
  * to `to`. Useful for direction-based operations.
  *
  * @param from Starting point.
  * @param to Target point.
  * @return A 2D vector representing the direction.
  *
  * @ingroup math_utils
  */
 t_dpoint	get_direction_vector(t_dpoint from, t_dpoint to)
 {
	 t_dpoint	vector;
 
	 vector.x = to.x - from.x;
	 vector.y = to.y - from.y;
	 return (vector);
 }
 
 /**
  * @brief Computes the angle of a 2D vector in radians.
  * 
  * @details
  * Uses `atan2(y, x)` to return the signed angle from the
  * positive x-axis to the vector direction.
  *
  * @param vector The 2D vector.
  * @return The angle in radians.
  *
  * @ingroup math_utils
  */
 double	get_vector_angle(t_dpoint vector)
 {
	 double	angle;
 
	 angle = atan2(vector.y, vector.x);
	 return (angle);
 }
 
 /**
  * @brief Computes the angle between two points as a direction vector.
  * 
  * @details
  * Forms a vector from `from` to `to`, then calculates its angle
  * from the x-axis using `atan2`. Useful for aiming or facing direction.
  *
  * @param from Starting point.
  * @param to Target point.
  * @return Angle in radians of the direction vector.
  *
  * @see get_direction_vector
  * @see get_vector_angle
  * @ingroup math_utils
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
  * @brief Computes the normalized direction vector between two points.
  * 
  * @details
  * Returns a unit-length vector pointing from `from` to `to`. This is
  * especially useful for movement or orientation systems.
  *
  * @param from Starting point.
  * @param to Target point.
  * @return The unit direction vector.
  *
  * @see get_direction_vector
  * @see get_normalized_vector
  * @ingroup math_utils
  */
 t_dpoint	get_unit_direction_vector(t_dpoint from, t_dpoint to)
 {
	 t_dpoint	direction_vector;
	 t_dpoint	unit_vector;
 
	 direction_vector = get_direction_vector(from, to);
	 unit_vector = get_normalized_vector(direction_vector);
	 return (unit_vector);
 }
 