/**
 * @file format_utils.c
 * @brief Utilities for handling padding, width, and precision in `ft_printf`.
 *
 * @details
 * This file contains utility functions used during format string interpretation
 * in `ft_printf`. It manages the logic for:
 * - Field width
 * - Padding with spaces or zeroes
 * - Precision for strings
 *
 * These functions interact with the `t_fmt` structure (format specifier)
 * and update output state through the `t_pf` structure.
 *
 * @author Toonsa
 * @date 2024/11/13
 * @ingroup ft_printf
 */

#include "libft.h"

/**
 * @brief Prints a series of padding characters.
 *
 * @details
 * This function prints `padding` number of characters (typically `' '` or
 * `'0'`) using `write_char_safely`. It is used to align formatted output to the
 * desired width.
 *
 * If a write error occurs, it sets `pf->write_error`.
 *
 * @param padding Number of characters to pad.
 * @param pad_char Character used for padding (usually ' ' or '0').
 * @param pf Print context to track output and errors.
 *
 * @see write_char_safely
 * @ingroup ft_printf
 */
void print_padding(int padding, char pad_char, t_pf* pf)
{
	while (padding-- > 0)
	{
		write_char_safely(1, pad_char, pf);
		if (pf->write_error)
			return;
	}
}

/**
 * @brief Applies precision limit to string length.
 *
 * @details
 * Truncates the given string length to the precision value if one
 * is specified (non-negative). Used when formatting `%s`.
 *
 * @param fmt Format specifier structure.
 * @param len Original string length.
 *
 * @return Truncated length if precision applies, otherwise original length.
 * @ingroup ft_printf
 */
int handle_precision_s(t_fmt* fmt, int len)
{
	if (fmt->precision >= 0 && fmt->precision < len)
		return (fmt->precision);
	return (len);
}

/**
 * @brief Computes the number of padding characters to apply.
 *
 * @details
 * Calculates how many characters must be padded to the left or right
 * to meet the field width requirement.
 *
 * @param fmt Format descriptor.
 * @param len Length of the current content to be printed.
 *
 * @return Number of characters to pad (may be zero).
 * @ingroup ft_printf
 */
int handle_width(t_fmt* fmt, size_t len)
{
	int padding;

	padding = fmt->width - (int) len;
	if (padding < 0)
		return (0);
	return (padding);
}
