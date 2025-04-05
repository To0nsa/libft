/**
 * @file ft_printf.c
 * @brief Custom printf implementation (`ft_printf` entry point).
 *
 * @details
 * This file provides the entry point for a simplified reimplementation of
 * `printf`, supporting format specifiers such as `%d`, `%s`, `%x`, `%p`, etc.
 *
 * The core logic:
 * - Initializes a `t_pf` structure to hold global state (errors, total written)
 * - Parses the format string with `process_format_string`
 * - Manages variadic arguments and error handling
 *
 * This implementation supports flags, width, precision, and basic types.
 * Internal helpers (formatters and printers) are grouped under `@ingroup ft_printf`.
 *
 * @author Toonsa
 * @date 2024/10/15
 * @ingroup ft_printf
 */

 #include "libft.h"

 /**
  * @brief Prints formatted output according to the format string.
  *
  * @details
  * Mimics the behavior of the standard `printf` function:
  * - Parses the format string
  * - Processes and prints each format specifier with its argument
  * - Uses internal state via `t_pf` to manage memory and write errors
  *
  * If a memory allocation or write operation fails, returns `-1`.
  *
  * @param format The format string (e.g. "Hello %s\n").
  * @param ... Variadic arguments matching format specifiers.
  *
  * @return The number of characters written, or `-1` on error.
  *
  * @note This function must be passed valid format and matching arguments.
  * @see initialize_printf_structs
  * @see process_format_string
  * @ingroup ft_printf
  */
 int	ft_printf(const char *format, ...)
 {
	 va_list	args;
	 t_pf	*pf;
	 int		total;
	 int		error;
 
	 error = 0;
	 if (format == NULL)
		 return (-1);
	 pf = (t_pf *)malloc(sizeof(t_pf));
	 if (pf == NULL)
		 return (-1);
	 if (initialize_printf_structs(pf) == -1)
		 return (-1);
	 va_start(args, format);
	 process_format_string(format, &args, pf);
	 va_end(args);
	 total = pf->total;
	 if (pf->malloc_error || pf->write_error)
		 error = -1;
	 free(pf->fmt);
	 free(pf);
	 return (error == -1 ? -1 : total);
 }
 