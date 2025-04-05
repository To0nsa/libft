/**
 * @file libft.h
 * @brief Hive Helsinki's custom C library (libft).
 *
 * This header declares the core functions and types used throughout the libft
 * project, a foundational library re-implementing standard C functions and
 * adding new utilities for string manipulation, memory handling, I/O,
 * linked lists, math, vector operations, and more.
 *
 * The functions are grouped using @defgroup and @ingroup for structured
 * documentation.
 *
 * @author nlouis
 * @date Created: 2024/10/21
 */
#ifndef LIBFT_H
# define LIBFT_H

# include "ft_array.h"
# include "ft_check.h"
# include "ft_file.h"
# include "ft_printf.h"
# include "ft_list.h"
# include "ft_math.h"
# include "ft_memory.h"
# include "ft_sorting.h"
# include "ft_string.h"
# include "ft_convert.h"



/**
 * @defgroup file_output File Output Functions
 * @brief Functions for writing characters, strings, and numbers to a file.
 *
 * This group includes functions that allow writing characters, strings, and
 * numbers to files. These functions are designed to provide easy ways to write
 * data to specified file descriptors.
 *
 * The following functions are included:
 * - `ft_putchar_fd`: Write a single character to a file descriptor.
 * - `ft_putendl_fd`: Write a string followed by a newline to a file descriptor.
 * - `ft_putnbr_fd`: Write an integer to a file descriptor.
 * - `ft_putstr_fd`: Write a string to a file descriptor.
 *
 * This group includes:
 * - @ref ft_putchar_fd
 * - @ref ft_putendl_fd
 * - @ref ft_putnbr_fd
 * - @ref ft_putstr_fd
 * @{
 */
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putstr_fd(char *s, int fd);
/** @} */  // end of file_output group

/**
 * @defgroup utilities Utilities Functions
 * @brief Utility functions for general-purpose operations.
 *
 * This group contains utility functions like `ft_swap` and `ft_rand`, which
 * perform general operations that are often needed in various situations. 
 * These functions include swapping values and generating random numbers.
 * 
 * This group includes:
 * - @ref ft_swap
 * - @ref ft_rand
 * @{
 */
void		ft_swap(void *a, void *b, size_t size);
int			ft_rand(int min, int max);
/** @} */  // end of utilities group

/* ************************************************************************** */
#endif /* LIBFT_H */
