/**
 * @file ft_math.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief Math and geometry utilities for libft.
 *
 * @details
 * This header provides various math-related helpers including:
 * - Angle conversions (degrees ↔ radians)
 * - Vector operations (length, normalization, dot product)
 * - 2D geometry helpers (distance between points, clamping, etc.)
 * 
 * @note Useful for graphics programming, simulations, and any system using basic geometry.
 *
 * @ingroup math_utils
 */

 #ifndef FT_MATH_H
 # define FT_MATH_H

 # include <math.h>		// sqrt, pow

/**
 * @defgroup math_utils Math and Vector Utilities
 * @brief Utility functions for angles, distances, and vector operations.
 *
 * @details
 * This group contains helper functions for geometric calculations such as
 * angle conversion, vector normalization, direction finding, and distance
 * measurement between points.
 *
 * Includes:
 * - Angle conversion (degrees ↔ radians)
 * - Distance calculations (Manhattan, Euclidean)
 * - Vector math (length, normalization, direction, dot product)
 * - Utility functions (clamp, wrap, etc.)
 * 
 * @note
 * All functions are pure and do not perform memory allocation.
 *
 * @{
 */

 /* ************************************************************************** */
 /*                              MACRO                                         */
 /* ************************************************************************** */

# ifndef M_PI
#  define M_PI				3.14159265358979323846	/**< Mathematical constant π */
# endif
 
 /* ************************************************************************** */
 /*                              TYPEDEFS                                      */
 /* ************************************************************************** */
 
 /**
  * @typedef t_point
  * @brief A simple struct for storing integer coordinates.
  *
  * @details
  * Represents a 2D point with integer precision.
  * - `x`: the horizontal component
  * - `y`: the vertical component
  */
 typedef struct s_point
 {
	 int	x;
	 int	y;
 }	t_point;
 
 /**
  * @typedef t_dpoint
  * @brief A simple struct for storing double float coordinates.
  *
  * @details
  * Represents a 2D point or vector with double-precision.
  * - `x`: the horizontal component
  * - `y`: the vertical component
  */
 typedef struct s_dpoint
 {
	 double	x;
	 double	y;
 }	t_dpoint;
 
 /* ************************************************************************** */
 /*                           FUNCTION PROTOTYPES                              */
 /* ************************************************************************** */
 
 double		deg_to_rad(double degrees);
 double		rad_to_deg(double radians);
 double		wrap_angle(double angle);
 int		ft_manhattan_dist_point(t_point a, t_point b);
 double		ft_manhattan_dist_dpoint(t_dpoint a, t_dpoint b);
 int		ft_euclidean_dist_point(t_point a, t_point b);
 double		ft_euclidean_dist_dpoint(t_dpoint a, t_dpoint b);
 double		clamp(double value, double min, double max);
 double		get_fractional_part(double value);
 double		wrap_in_range(double value, double range);
 double		get_vector_length(t_dpoint vec);
 t_dpoint	divide_vector_by_scalar(t_dpoint vec, double scalar);
 t_dpoint	get_normalized_vector(t_dpoint vector);
 double		get_vector_angle(t_dpoint vector);
 double		get_vector_angle_between(t_dpoint from, t_dpoint to);
 t_dpoint	get_direction_vector(t_dpoint from, t_dpoint to);
 t_dpoint	get_unit_direction_vector(t_dpoint from, t_dpoint to);
 double		get_dot_product(t_dpoint vec1, t_dpoint vec2);
 /** @} */
 
 #endif // FT_MATH_H
 