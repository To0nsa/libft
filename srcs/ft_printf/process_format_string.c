/**
 * @file process_format_string.c
 * @brief Parses and handles format specifiers for ft_printf.
 *
 * @details
 * This module implements the parsing logic for the custom `ft_printf`
 * function. It scans the format string, identifies conversion specifiers,
 * resets formatting context, and dispatches printing to the appropriate
 * handler functions based on the type.
 *
 * Supported specifiers: `%c`, `%s`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`.
 *
 * @author Toonsa
 * @date 2024/10/30
 * @ingroup ft_printf
 */

 #include "libft.h"

 /**
  * @brief Delegates the specifier to the appropriate formatter.
  *
  * @param fmt Current format context (`t_fmt`).
  * @param args Active variadic argument list.
  * @param pf Print state tracker (`t_pf`).
  *
  * @see format_and_print_c
  * @see format_and_print_s
  * @see format_and_print_id
  * @see format_and_print_u
  * @see format_and_print_x
  * @see format_and_print_percent
  * @ingroup ft_printf
  */
 static void	parse_and_handle_specifier(t_fmt *fmt, va_list *args, t_pf *pf)
 {
	 if (fmt->specifier == 'c')
		 format_and_print_c(fmt, args, pf);
	 else if (fmt->specifier == 's')
		 format_and_print_s(fmt, args, pf);
	 else if (fmt->specifier == 'i' || fmt->specifier == 'd')
		 format_and_print_id(fmt, args, pf);
	 else if (fmt->specifier == 'u')
		 format_and_print_u(fmt, args, pf);
	 else if (fmt->specifier == 'x')
		 format_and_print_x(fmt, args, 0, pf);
	 else if (fmt->specifier == 'X')
		 format_and_print_x(fmt, args, 1, pf);
	 else if (fmt->specifier == '%')
		 format_and_print_percent(fmt, pf);
 }
 
 /**
  * @brief Resets the format context for the next conversion.
  *
  * @param fmt The format descriptor to reset.
  *
  * @ingroup ft_printf
  */
 static void	reset_fmt(t_fmt *fmt)
 {
	 fmt->flags = 0;
	 fmt->width = 0;
	 fmt->precision = -1;
	 fmt->specifier = '\0';
 }
 
 /**
  * @brief Parses a single conversion specifier after `%`.
  *
  * @details
  * This function processes the format string starting from the current
  * cursor. It resets the format context, sets up the format
  * descriptor, and dispatches the appropriate formatter.
  * If the format is invalid, it prints the raw characters until the
  * next `%` or end of string.
  *
  * @param format Pointer to the current cursor in the format string.
  * @param args Argument list used for conversions.
  * @param pf Print state context.
  *
  * @see setup_format
  * @see reset_fmt
  * @see parse_and_handle_specifier
  * @see write_char_safely
  * @ingroup ft_printf
  */
 static void	process_conv_spec(const char **format, va_list *args, t_pf *pf)
 {
	 const char	*start_format;
 
	 reset_fmt(pf->fmt);
	 start_format = *format - 1;
	 if (setup_format(format, pf->fmt) == -1)
	 {
		 while (start_format < *format)
		 {
			 write_char_safely(1, *start_format, pf);
			 if (pf->write_error != 0)
				 return ;
			 start_format++;
		 }
		 return ;
	 }
	 parse_and_handle_specifier(pf->fmt, args, pf);
 }
 
 /**
  * @brief Walks through the format string and dispatches format handlers.
  *
  * @details
  * This is the main format processing loop for `ft_printf`. It iterates
  * through the characters in the format string. When encountering `%`,
  * it parses and processes a specifier. Otherwise, it prints the character.
  *
  * @param format The format string to parse.
  * @param args The active variadic arguments.
  * @param pf Print state context.
  *
  * @see process_conv_spec
  * @see write_char_safely
  * @ingroup ft_printf
  */
 void	process_format_string(const char *format, va_list *args, t_pf *pf)
 {
	 while (*format)
	 {
		 if (*format == '%')
		 {
			 format++;
			 if (*format == '\0')
				 return ;
			 process_conv_spec(&format, args, pf);
			 if (pf->write_error != 0 || pf->malloc_error != 0)
				 return ;
		 }
		 else
		 {
			 write_char_safely(1, *format, pf);
			 if (pf->write_error != 0)
				 return ;
			 format++;
		 }
	 }
 }
 