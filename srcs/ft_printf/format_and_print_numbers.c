/**
 * @file format_and_print_numbers.c
 * @brief Handles numeric specifiers for ft_printf.
 *
 * @details
 * This file implements support for numeric format specifiers in `ft_printf`:
 * - `%d` / `%i` (signed integers)
 * - `%u` (unsigned integers)
 * - `%x` / `%X` (hexadecimal values)
 *
 * Each function retrieves the relevant argument from the `va_list`, converts it
 * to a string, applies formatting (precision, padding, width), and delegates
 * final output to `print_formatted_number`.
 *
 * @author Toonsa
 * @date 2024/10/29
 * @ingroup ft_printf
 */

 #include "libft.h"

 /**
  * @brief Handles `%d` and `%i` format specifiers for ft_printf.
  *
  * @details
  * Converts an integer value to string using `ft_itoa`, applies formatting
  * using `handle_precision_int`, and writes the result using
  * `print_formatted_number`. If a memory allocation fails, the `malloc_error`
  * flag is set in the state struct.
  *
  * @param fmt Format descriptor (flags, width, precision).
  * @param args Pointer to `va_list` with the argument.
  * @param pf State struct tracking write progress and error flags.
  *
  * @see ft_itoa
  * @see handle_precision_int
  * @see print_formatted_number
  * @ingroup ft_printf
  */
 void	format_and_print_id(t_fmt *fmt, va_list *args, t_pf *pf)
 {
	 int	num;
	 char	*str;
	 int	len;
 
	 num = va_arg(*args, int);
	 str = ft_itoa(num);
	 if (!str)
	 {
		 pf->malloc_error = 1;
		 return ;
	 }
	 len = ft_strlen(str);
	 str = handle_precision_int(fmt, str, &len, pf);
	 if (!str)
		 return ;
	 print_formatted_number(fmt, str, len, pf);
 }
 
 /**
  * @brief Handles `%u` format specifier for ft_printf.
  *
  * @details
  * Converts an unsigned integer to string using `ft_utoa`, applies precision,
  * and writes the formatted result using `print_formatted_number`.
  *
  * @param fmt Format descriptor (flags, width, precision).
  * @param args Pointer to `va_list` with the argument.
  * @param pf State struct tracking write progress and error flags.
  *
  * @see ft_utoa
  * @see handle_precision_int
  * @see print_formatted_number
  * @ingroup ft_printf
  */
 void	format_and_print_u(t_fmt *fmt, va_list *args, t_pf *pf)
 {
	 unsigned int	num;
	 char			*str;
	 int			len;
 
	 num = va_arg(*args, unsigned int);
	 str = ft_utoa(num);
	 if (!str)
		 return ;
	 len = ft_strlen(str);
	 str = handle_precision_int(fmt, str, &len, pf);
	 if (!str)
		 return ;
	 print_formatted_number(fmt, str, len, pf);
 }
 
 /**
  * @brief Handles `%x` and `%X` format specifiers for ft_printf.
  *
  * @details
  * Converts an unsigned integer to hexadecimal using `ft_itoa_base`, applies
  * precision, and prints the formatted result. If `upper` is non-zero, the
  * hexadecimal letters are uppercase (for `%X`).
  *
  * @param fmt Format descriptor (flags, width, precision).
  * @param args Pointer to `va_list` with the argument.
  * @param upper If non-zero, use uppercase letters in output.
  * @param pf State struct tracking write progress and error flags.
  *
  * @see ft_itoa_base
  * @see handle_precision_int
  * @see print_formatted_number
  * @ingroup ft_printf
  */
 void	format_and_print_x(t_fmt *fmt, va_list *args, int upper, t_pf *pf)
 {
	 unsigned int	num;
	 char			*str;
	 int				len;
 
	 num = va_arg(*args, unsigned int);
	 str = ft_itoa_base(num, 16, upper);
	 if (!str)
		 return ;
	 len = ft_strlen(str);
	 str = handle_precision_int(fmt, str, &len, pf);
	 if (!str)
		 return ;
	 print_formatted_number(fmt, str, len, pf);
 }
 