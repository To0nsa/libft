/**
 * @file libft.h
 * @author Toonsa
 * @date 2024/10/21
 * @brief My custom C library (libft).
 *
 * @details
 * This header serves as the central aggregator for the libft project.
 * It does not declare any functions or types directly, but includes
 * all modular headers that implement core features of the library.
 *
 * These features include memory and string manipulation, character
 * classification, formatted output, mathematical operations, dynamic
 * arrays, matrix utilities, and more.
 *
 * This header allows external programs to access the entire libft
 * functionality through a single include.
 *
 * @ingroup core
 */
#ifndef LIBFT_H
#define LIBFT_H

#include <errno.h>    /* errno, EINTR, etc. */
#include <fcntl.h>    /* open, close, file control */
#include <limits.h>   /* INT_MAX, LLONG_MAX, etc. */
#include <math.h>     /* floor, sqrt, pow, etc. */
#include <stdarg.h>   /* va_list for ft_printf */
#include <stdbool.h>  /* bool type (C99) */
#include <stdint.h>   /* uint64_t, etc. */
#include <stdio.h>    /* perror, printf for debugging */
#include <stdlib.h>   /* malloc, free, exit, etc. */
#include <string.h>   /* to be able to use it in other projects */
#include <sys/time.h> /* gettimeofday for ft_rand */
#include <unistd.h>   /* write, read, close, etc. */

/* --- Libft module headers --- */
#include "ft_2darray.h"
#include "ft_array.h"
#include "ft_check.h"
#include "ft_convert.h"
#include "ft_file.h"
#include "ft_list.h"
#include "ft_math.h"
#include "ft_memory.h"
#include "ft_output.h"
#include "ft_printf.h"
#include "ft_sorting.h"
#include "ft_string.h"
#include "ft_utils.h"

#endif /* LIBFT_H */
