/**
 * @file format_print_csper.c
 * @brief Handles printing of `%c`, `%s`, and `%%` specifiers for ft_printf.
 *
 * @details
 * This file implements the formatting and output logic for the character,
 * string, and literal percent sign specifiers in `ft_printf`. Each function
 * handles its corresponding format specifier using:
 * - Width and alignment
 * - Padding
 * - Precision (for strings)
 *
 * All output operations go through the state-tracking `t_pf` struct.
 *
 * @author Toonsa
 * @date 2024/11/08
 * @ingroup ft_printf
 */

#include "libft.h"

/**
 * @brief Formats and prints a literal percent sign (`%%`).
 *
 * @details
 * Prints a single percent character with optional width padding.
 * Padding is done with `' '` or `'0'`, and alignment respects the
 * `FLAG_MINUS` flag.
 *
 * @param fmt Format descriptor (width and flags).
 * @param pf Print context for error tracking and byte count.
 *
 * @see handle_width
 * @see print_padding
 * @see write_char_safely
 * @ingroup ft_printf
 */
void format_and_print_percent(t_fmt* fmt, t_pf* pf)
{
	int  padding;
	char pad_char;

	pad_char = (fmt->flags & FLAG_ZERO) ? '0' : ' ';
	padding  = handle_width(fmt, 1);
	if (!(fmt->flags & FLAG_MINUS))
	{
		print_padding(padding, pad_char, pf);
		if (pf->write_error)
			return;
	}
	write_char_safely(1, '%', pf);
	if (pf->write_error)
		return;
	if (fmt->flags & FLAG_MINUS)
		print_padding(padding, ' ', pf);
}

/**
 * @brief Formats and prints a character (`%c`).
 *
 * @details
 * Retrieves a single character from the variadic list and prints it
 * with optional alignment and width padding.
 *
 * @param fmt Format specifier structure.
 * @param args Argument list containing the character.
 * @param pf Print context structure.
 *
 * @see write_char_safely
 * @see handle_width
 * @see print_padding
 * @ingroup ft_printf
 */
void format_and_print_c(t_fmt* fmt, va_list* args, t_pf* pf)
{
	char c;
	int  padding;

	c       = va_arg(*args, int);
	padding = handle_width(fmt, 1);
	if (!(fmt->flags & FLAG_MINUS))
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error)
			return;
	}
	write_char_safely(1, c, pf);
	if (pf->write_error)
		return;
	if (fmt->flags & FLAG_MINUS)
		print_padding(padding, ' ', pf);
}

/**
 * @brief Formats and prints a string (`%s`).
 *
 * @details
 * Retrieves a string from the variadic list and prints it with optional
 * width, alignment, and precision. NULL strings are replaced by `"(null)"`.
 *
 * If a precision is set, the string is truncated to that length.
 * Alignment follows the `FLAG_MINUS` flag.
 *
 * @param fmt Format descriptor for width and precision.
 * @param args Variadic arguments (string to print).
 * @param pf Print state and error tracking.
 *
 * @see handle_precision_s
 * @see write_safely_len
 * @see handle_width
 * @see print_padding
 * @ingroup ft_printf
 */
void format_and_print_s(t_fmt* fmt, va_list* args, t_pf* pf)
{
	char*  str;
	size_t len;
	int    padding;

	str = va_arg(*args, char*);
	if (!str)
		str = "(null)";
	len     = ft_strlen(str);
	len     = handle_precision_s(fmt, len);
	padding = handle_width(fmt, len);
	if (!(fmt->flags & FLAG_MINUS))
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error)
			return;
	}
	write_safely_len(1, str, len, pf);
	if (pf->write_error)
		return;
	if (fmt->flags & FLAG_MINUS)
		print_padding(padding, ' ', pf);
}
