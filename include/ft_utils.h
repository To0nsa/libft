/**
 * @file ft_utils.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief Utility functions for general-purpose operations.
 *
 * @details
 * This header declares generic helper functions used throughout various
 * parts of a project, such as memory-safe value swapping and bounded
 * random number generation.
 *
 * @ingroup utilities
 */

 #ifndef FT_UTILS_H
 # define FT_UTILS_H
 
 # include <stddef.h> // for size_t
 
 /**
  * @defgroup utilities Utilities Functions
  * @brief Utility functions for general-purpose operations.
  *
  * @details
  * This group contains utility functions like `ft_swap` and `ft_rand`, which
  * perform general operations that are often needed in various situations. 
  * These functions include swapping values and generating random numbers.
  * 
  * @{
  */
 
 void	ft_swap(void *a, void *b, size_t size);
 int		ft_rand(int min, int max);
 
 /** @} */ // end of utilities group
 
 #endif
 