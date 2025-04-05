/**
 * @file ft_convert.h
 * @author ...
 * @date 2025-04-05
 * @brief Numeric conversion utility functions.
 *
 * @details
 * This header declares functions used for converting between
 * numeric values and their string representations, handling
 * bases, signs, and overflow.
 *
 * @ingroup number_conversions
 */

 #ifndef FT_CONVERT_H
 # define FT_CONVERT_H
 
 # include <stddef.h> // size_t
 # include <stdbool.h> // bool
 # include <limits.h> // INT_MAX, INT_MIN
 
 # ifndef ATOI_ERROR
 #  define ATOI_ERROR (-2147483648LL) /**< Error return for atoi overflow */
 # endif
 
 /**
  * @defgroup number_conversions Number Conversion Utilities
  * @brief String ↔ number conversion and formatting.
  *
  * @details
  * This group provides functions to convert strings to numbers
  * (like `ft_atoi` and `ft_atoll`) with overflow detection, and
  * to format unsigned integers into strings, optionally in base
  * 2 to 16.
  * 
  *This group includes:
  * - @ref ft_atoi
  * - @ref ft_atoll
  * - @ref ft_utoa
  * - @ref ft_itoa_base
  *
  * @{
  */
 
 long long	ft_atoi(const char *str);
 long long	ft_atoll(const char *str);
 char		*ft_utoa(unsigned long long n);
 char		*ft_itoa_base(unsigned long long n, int base, int uppercase);
 
 /** @} */ // end of number_conversions group
 
 #endif
 