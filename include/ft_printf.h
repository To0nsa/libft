/**
 * @file ft_printf.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief Internal definitions and declarations for ft_printf.
 *
 * @details
 * This header contains all the structures, macros, and function prototypes
 * required to implement a custom `ft_printf`. It supports parsing format
 * strings, handling flags, and printing various types (characters, strings,
 * integers, hexadecimal, pointers, etc.).
 *
 * It also defines the `FLAG_*` macros for internal format flag management.
 *
 * @ingroup ft_printf
 */

 #ifndef FT_PRINTF_H
 # define FT_PRINTF_H
 
 # include <stdarg.h>
 # include <stddef.h>
 # include <errno.h>
 
 /**
  * @defgroup ft_printf Formatted Output (ft_printf)
  * @brief Custom implementation of the printf function.
  *
  * @details
  * This group includes all functions involved in the implementation
  * of `ft_printf`, including:
  *
  * - Format string parsing
  * - Handling of flags, width, precision
  * - Type specifiers (e.g., %d, %s, %x, etc.)
  * @{
  */
 
 # define FLAG_HASH    (1 << 0)  /**< '#' flag: alternate form */
 # define FLAG_ZERO    (1 << 1)  /**< '0' flag: zero padding */
 # define FLAG_MINUS   (1 << 2)  /**< '-' flag: left-justify */
 # define FLAG_PLUS    (1 << 3)  /**< '+' flag: show plus sign */
 # define FLAG_SPACE   (1 << 4)  /**< ' ' flag: leading space */
 
 /**
  * @struct s_fmt
  * @brief Format specifier data.
  *
  * Stores parsed flags, field width, precision, and the actual type specifier.
  */
 typedef struct s_fmt
 {
	 int		flags;
	 int		width;
	 int		precision;
	 char	specifier;
 }	t_fmt;
 
 /**
  * @struct s_pf
  * @brief State struct for ft_printf.
  *
  * Keeps track of total characters written, and internal errors.
  */
 typedef struct s_pf
 {
	 int		total;
	 int		write_error;
	 int		malloc_error;
	 t_fmt	*fmt;
 }	t_pf;
 
 int	ft_printf(const char *format, ...);
 int	initialize_printf_structs(t_pf *pf);
 void	process_format_string(const char *format, va_list *args, t_pf *pf);
 
 void	write_safely(int fd, char *str, t_pf *pf);
 void	write_safely_len(int fd, char *str, size_t len, t_pf *pf);
 void	write_char_safely(int fd, char c, t_pf *pf);
 
 int	is_valid_flag(char c);
 int	setup_format(const char **format, t_fmt *fmt);
 void	print_padding(int padding, char pad_char, t_pf *pf);
 
 int	handle_precision_s(t_fmt *fmt, int len);
 int	handle_width(t_fmt *fmt, size_t len);
 
 void	format_and_print_c(t_fmt *fmt, va_list *args, t_pf *pf);
 void	format_and_print_s(t_fmt *fmt, va_list *args, t_pf *pf);
 void	format_and_print_percent(t_fmt *fmt, t_pf *pf);
 
 void	format_and_print_id(t_fmt *fmt, va_list *args, t_pf *pf);
 void	format_and_print_u(t_fmt *fmt, va_list *args, t_pf *pf);
 void	format_and_print_x(t_fmt *fmt, va_list *args, int upper, t_pf *pf);
 
 char	*handle_precision_int(t_fmt *fmt, char *str, int *len, t_pf *pf);
 void	print_formatted_number(t_fmt *fmt, char *str, int len, t_pf *pf);
 
 char	*handle_precision_p(t_fmt *fmt, char *str, int *len, t_pf *pf);
 void	handle_space_flag_p(t_pf *pf, int *padding);
 void	handle_minus_flag_p(char *str, int padding, t_pf *pf);
 void	print_right_aligned_p(t_fmt *fmt, char *str, int padding, t_pf *pf);
 
 int	requires_alternative_form(char specifier, char *str);
 char	*prepend_alternative_form(char *str, char specifier, t_pf *pf);
 int	get_alternative_form_length(char specifier);
 
 /** @} */ // end of ft_printf group
 
 #endif
 