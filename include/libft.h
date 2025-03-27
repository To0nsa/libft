/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:23:16 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/27 14:01:32 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                         STANDARD LIBRARIES & HEADERS                       */
/* ************************************************************************** */
/**
 * @section standard_headers Standard Library Includes
 * @brief Includes standard C headers used throughout libft.
 *
 * These headers provide access to core library functions such as memory
 * allocation, file I/O, variable arguments, math functions, and types.
 */
# include <unistd.h>	/* write, read, close, etc. */
# include <stdlib.h>	/* malloc, free, exit, etc. */
# include <limits.h>	/* INT_MAX, LLONG_MAX, etc. */
# include <stdarg.h>	/* va_list for ft_printf */
# include <stdbool.h>	/* bool type (C99) */
# include <errno.h>		/* errno, EINTR, etc. */
# include <fcntl.h>		/* open, close, file control */
# include <sys/time.h>	/* gettimeofday for ft_rand */
# include <math.h>		/* floor, sqrt, pow, etc. */
# include <stddef.h>	/* size_t, NULL */
# include <stdint.h>	/* uint64_t, etc. */
# include <stdio.h>		/* perror, printf for debugging */

/* ************************************************************************** */
/*                              MACRO DEFINITIONS                             */
/* ************************************************************************** */

# define BUFFER_SIZE		1024		/**< Default buffer size */
# define MAX_FD				1024		/**< Maximum file descriptor index */

# define QSORT_THRESHOLD	10			/**< Threshold to switch sort strategy */

# define FLAG_HASH			(1 << 0)	/**< '#' flag */
# define FLAG_ZERO			(1 << 1)	/**< '0' flag */
# define FLAG_MINUS			(1 << 2)	/**< '-' flag */
# define FLAG_PLUS			(1 << 3)	/**< '+' flag */
# define FLAG_SPACE			(1 << 4)	/**< ' ' flag */

# define ATOI_ERROR			9223372036854775807LL	/**< Returned by atoi on overflow */

# ifndef M_PI
#  define M_PI				3.14159265358979323846	/**< Mathematical constant π */
# endif

/* ************************************************************************** */
/*                              TYPE DEFINITIONS                              */
/* ************************************************************************** */

/**
 * @typedef t_point
 * @brief A simple struct for storing integer coordinates.
 */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/**
 * @typedef t_dpoint
 * @brief A simple struct for storing double float coordinates.
 */
typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

/**
 * @typedef t_list
 * @brief A generic singly-linked list node.
 *
 * This structure is used to build singly-linked lists, where each node
 * contains a pointer to some data (`content`) and a pointer to the next node.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @typedef t_fmt
 * @brief Format specifier structure used by ft_printf.
 *
 * Holds the parsed format options for a single conversion in ft_printf,
 * such as flags, width, precision, and the specifier character.
 */
typedef struct s_fmt
{
	int		flags;
	int		width;
	int		precision;
	char	specifier;
}	t_fmt;

/**
 * @typedef t_pf
 * @brief Internal state tracker for the ft_printf implementation.
 *
 * This structure holds the state for an ongoing ft_printf call, including
 * error flags and a pointer to the current format specifier.
 */
typedef struct s_pf
{
	int		total;
	int		write_error;
	int		malloc_error;
	t_fmt	*fmt;
}	t_pf;

/* ************************************************************************** */
/*                           FUNCTION PROTOTYPES                              */
/* ************************************************************************** */

/**
 * @defgroup array_utils Array Utilities
 * @brief Functions for working with pointer arrays (char**, void**, etc.).
 *
 * Includes functions like copying, freeing, measuring size of arrays, etc.
 * This group is useful for handling string arrays, environment variables, etc.
 * It contains :
 * @ref ft_arraysize
 * @ref ft_copy_strarray
 * @ref ft_free_array
 * @ref ft_free_array_size
 * @ref ft_putintarray
 * @ref ft_is_array_sorted
 */
size_t		ft_arraysize(void **array);
char		**ft_copy_strarray(char **array);
void		ft_free_array(void **array);
void		ft_free_array_size(void **array, size_t size);
int			ft_putintarray(int *array, int size);
bool		ft_is_array_sorted(const int *array, size_t size);

/**
 * @defgroup char_check Character Classification
 * @brief Custom implementations of character check functions.
 *
 * These functions test individual characters against specific conditions,
 * such as whether they are digits, letters, punctuation marks, whitespace,
 * printable, etc. They are useful in parsing, formatting, and validation
 * tasks where character-level logic is needed.
 *
 * This group includes:
 * - @ref ft_isalpha
 * - @ref ft_isdigit
 * - @ref ft_isascii
 * - @ref ft_isalnum
 * - @ref ft_islower
 * - @ref ft_isupper
 * - @ref ft_isspace
 * - @ref ft_issign
 * - @ref ft_ispunct
 * - @ref ft_isprint
 * - @ref ft_isstrpositive
 */
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
bool		ft_is_valid_integer(const char *str);
int			ft_isprint(int c);
int			ft_ispunct(int c);
int			ft_isspace(int c);
int			ft_islower(int c);
int			ft_isupper(int c);
int			ft_issign(int c);
int			ft_isstrpositive(const char *str);

/**
 * @defgroup file_utils File Utilities
 * @brief Helper functions for basic file operations.
 *
 * This group contains get_next_line and simple wrapper functions around
 * common file operations such as opening, reading, and closing files. These
 * functions add basic error checking and consistent error reporting
 * to simplify file handling across your project.
 *
 * This group includes:
 * - @ref ft_open_file
 * - @ref ft_read_file
 * - @ref ft_safe_close
 * - @ref get_next_line
 */
int			ft_open_file(const char *filename, int flags);
ssize_t		ft_read_file(int fd, void *buffer, size_t size);
int			ft_safe_close(int fd);
char		*get_next_line(int fd);

/**
 * @defgroup ft_printf Formatted Output (ft_printf)
 * @brief Custom implementation of the printf function.
 *
 * This group includes all functions involved in the implementation
 * of `ft_printf`, including:
 *
 * - Format string parsing
 * - Handling of flags, width, precision
 * - Type specifiers (e.g., %d, %s, %x, etc.)
 *
 * The main function is `ft_printf`, and its helpers are
 * documented here to provide a complete overview of how formatted
 * output is constructed.
 *
 * @{
 */
int			ft_printf(const char *format, ...);
int			initialize_printf_structs(t_pf *pf);
void		process_format_string(const char *format, va_list *args, t_pf *pf);
void		write_safely(int fd, char *str, t_pf *pf);
void		write_safely_len(int fd, char *str, size_t len, t_pf *pf);
void		write_char_safely(int fd, char c, t_pf *pf);
int			is_valid_flag(char c);
int			setup_format(const char **format, t_fmt *fmt);
void		print_padding(int padding, char pad_char, t_pf *pf);
int			handle_precision_s(t_fmt *fmt, int len);
int			handle_width(t_fmt *fmt, size_t len);
void		format_and_print_c(t_fmt *fmt, va_list *args, t_pf *pf);
void		format_and_print_s(t_fmt *fmt, va_list *args, t_pf *pf);
void		format_and_print_percent(t_fmt *fmt, t_pf *pf);

char		*handle_precision_p(t_fmt *fmt, char *str, int *len, t_pf *pf);
void		handle_space_flag_p(t_pf *pf, int *padding);
void		handle_minus_flag_p(char *str, int padding, t_pf *pf);
void		print_right_aligned_p(t_fmt *fmt, char *str, int padding, t_pf *pf);
void		format_and_print_id(t_fmt *fmt, va_list *args, t_pf *pf);
void		format_and_print_u(t_fmt *fmt, va_list *args, t_pf *pf);
void		format_and_print_x(t_fmt *fmt, va_list *args, int upper, t_pf *pf);
char		*handle_precision_int(t_fmt *fmt, char *str, int *len, t_pf *pf);
void		print_formatted_number(t_fmt *fmt, char *str, int len, t_pf *pf);
int			requires_alternative_form(char specifier, char *str);
char		*prepend_alternative_form(char *str, char specifier, t_pf *pf);
int			get_alternative_form_length(char specifier);
/** @} */  // end of ft_printf group

/**
 * @defgroup linked_list Linked List Utilities
 * @brief Singly linked list manipulation functions.
 *
 * This group contains all the functions related to the manipulation
 * of singly linked lists, including creation, insertion, deletion,
 * traversal, and transformation.
 *
 * These utilities operate on a `t_list` structure, typically defined as:
 * ```c
 * typedef struct s_list {
 *     void            *content;
 *     struct s_list   *next;
 * } t_list;
 * ```
 *
 * This group includes:
 * - @ref ft_lstnew
 * - @ref ft_lstadd_front
 * - @ref ft_lstsize
 * - @ref ft_lstlast
 * - @ref ft_lstadd_back
 * - @ref ft_lstdelone
 * - @ref ft_lstclear
 * - @ref ft_lstiter
 * - @ref ft_lstmap
 * - @ref ft_del
 * @{
 */
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_del(void *content);
/** @} */ // end of linked_list group

/**
 * @defgroup math_utils Math and Vector Utilities
 * @brief Utility functions for angles, distances, and vector operations.
 *
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
 * This group includes:
 * - @ref deg_to_rad
 * - @ref rad_to_deg
 * - @ref wrap_angle
 * - @ref ft_manhattan_dist_point
 * - @ref fr_manhattan_dist_dpoint
 * - @ref ft_euclidean_dist_point
 * - @ref ft_euclidean_dist_dpoint
 * - @ref clamp
 * - @ref get_fractional_part
 * - @ref wrap_in_range
 * - @ref get_vector_length
 * - @ref divide_vector_by_scalar
 * - @ref get_normalized_vector
 * - @ref get_vector_angle
 * - @ref get_vector_angle_between
 * - @ref get_direction_vector
 * - @ref get_unit_direction_vector
 * - @ref get_dot_product
 * @{
 */
double		deg_to_rad(double degrees);
double		rad_to_deg(double radians);
double		wrap_angle(double angle);
int			ft_manhattan_dist_point(t_point a, t_point b);
double		ft_manhattan_dist_dpoint(t_dpoint a, t_dpoint b);
int			ft_euclidean_dist_point(t_point a, t_point b);
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
/** @} */ // end of math_utils group

/**
 * @defgroup matrix_utils Matrix Utilities
 * @brief Utilities for working with integer matrices.
 *
 * These functions are designed to create, copy, convert, print, and free
 * dynamically allocated 2D integer arrays (matrices).
 *
 * Useful for grid-based applications such as game maps or algorithmic tasks.
 *
 * This group includes:
 * - @ref ft_matrix_copy
 * - @ref ft_create_matrix
 * - @ref ft_free_matrix
 * - @ref ft_print_matrix
 * - @ref ft_strarr_to_matrix
 * @{
 */
int			**ft_matrix_copy(int **matrix, size_t rows, size_t cols);
int			**ft_create_matrix(size_t rows, size_t cols);
void		ft_free_matrix(int **matrix, size_t rows);
int			ft_print_matrix(int **matrix, size_t rows, size_t cols);
int			**ft_strarr_to_matrix(char **array);
/** @} */ // end of matrix_utils group

/**
 * @defgroup memory_utils Memory Management
 * @brief Functions for low-level memory operations.
 *
 * This group contains functions that replicate or extend common C
 * standard library memory operations, including:
 * 
 * - Allocation (`ft_calloc`, `ft_realloc`)
 * - Initialization (`ft_bzero`, `ft_memset`)
 * - Copying and moving (`ft_memcpy`, `ft_memmove`)
 * - Comparison and search (`ft_memcmp`, `ft_memchr`)
 *
 * These utilities provide safer or more convenient alternatives to their
 * standard counterparts and are useful throughout custom C projects.
 *
 * This group includes:
 * - @ref ft_calloc
 * - @ref ft_realloc
 * - @ref ft_bzero
 * - @ref ft_memchr
 * - @ref ft_memcmp
 * - @ref ft_memcpy
 * - @ref ft_memmove
 * - @ref ft_memset
 * @{
 */
void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *buffer, int c, size_t count);
int			ft_memcmp(const void *buffer1, const void *buffer2, size_t count);
void		*ft_memcpy(void *dest, const void *src, size_t count);
void		*ft_memmove(void *dest, const void *src, size_t count);
void		*ft_memset(void *dest, int c, size_t count);
/** @} */ // end of memory_utils group

/**
 * @defgroup sorting_utils Sorting Utilities
 * @brief General-purpose sorting utilities including a custom quicksort.
 *
 * This group contains functions related to sorting arrays using a generic
 * implementation of the quicksort algorithm. It also includes basic comparator
 * functions for integers and doubles that can be passed to `ft_qsort`.
 *
 * @{
 */
void	ft_qsort(void *base, size_t nmemb, size_t size, int (*cmp)(const void *, const void *));
int		double_cmp(const void *a, const void *b);
int		int_cmp(const void *a, const void *b);
/** @} */ // end of sorting_utils group

/**
 * @defgroup string_utils String Manipulation Utilities
 * @brief Functions for handling and manipulating C strings.
 *
 * This group includes common string operations such as copying,
 * concatenation, trimming, splitting, searching, and case conversion.
 *
 * Useful for tasks like:
 * - Extracting substrings
 * - Skipping whitespace
 * - Finding characters or substrings
 * - Transforming string content
 *
 * This group includes:
 * - @ref ft_strcat
 * - @ref ft_split_charset
 * - @ref ft_split
 * - @ref ft_strchr
 * - @ref ft_strcpy
 * - @ref ft_strdup
 * - @ref ft_striteri
 * - @ref ft_strjoin
 * - @ref ft_strjoin_and_free
 * - @ref ft_strlcat
 * - @ref ft_strlcpy
 * - @ref ft_strlen
 * - @ref ft_strmapi
 * - @ref ft_strcmp
 * - @ref ft_strncmp
 * - @ref ft_strndup
 * - @ref ft_strnstr
 * - @ref ft_strrchr
 * - @ref ft_strtrim
 * - @ref ft_substr
 * - @ref ft_tolower
 * - @ref ft_toupper
 * - @ref skip_whitespace_index
 * - @ref skip_whitespace_ptr
 * @{
 */
char		*ft_strcat(char *dest, const char *src);
char		**ft_split_charset(char *s, char *charset);
char		**ft_split(const char *s, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *src);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_and_free(char *s1, char *s2, int free_s1, int free_s2);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strndup(const char *src, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *str, int c);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		skip_whitespace_index(const char *input, int *i);
char		*skip_whitespace_ptr(const char *s);
/** @} */ // end of string_utils group

/**
 * @defgroup number_conversions Integer and String Conversions
 * @brief Functions to convert between integers and strings.
 *
 * This group contains functions that handle integer-to-string and 
 * string-to-integer conversions, as well as custom base conversions.
 * These utilities are useful for handling different types of numeric 
 * representations and parsing data.
 *
 * This group includes:
 * - @ref ft_atoi
 * - @ref ft_atoll
 * - @ref ft_itoa
 * - @ref ft_utoa
 * - @ref ft_itoa_base
 * @{
 */
long long	ft_atoi(const char *str);
long long	ft_atoll(const char *str);
char		*ft_itoa(long long n);
char		*ft_utoa(unsigned long long n);
char		*ft_itoa_base(unsigned long long n, int base, int uppercase);
/** @} */  // end of number_conversions group

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
