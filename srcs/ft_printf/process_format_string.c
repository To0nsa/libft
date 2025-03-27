/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:16:11 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:23 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file process_format_string.c
 * @brief Format string parsing for ft_printf implementation.
 *
 * This file contains the core parsing logic of the custom `ft_printf`
 * function. It processes the format string, handles conversion specifiers,
 * resets formatting context between specifiers, and delegates printing
 * to the appropriate handlers.
 *
 * @author nlouis
 * @date 2024/10/30
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Dispatches the formatting logic based on the specifier type.
 *
 * This function calls the appropriate handler for a given conversion
 * specifier (e.g., `%d`, `%s`, `%x`, etc.) stored in the `t_fmt` structure.
 *
 * @param fmt Pointer to the format specifier structure.
 * @param args Pointer to the variadic arguments list.
 * @param pf Pointer to the print state tracker (`t_pf`).
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
	if (pf->write_error != 0 || pf->malloc_error != 0)
		return ;
}

/**
 * @brief Resets the format specifier structure to default values.
 *
 * This clears any previously stored flags, width, precision, or
 * specifier so the structure is ready for the next conversion.
 *
 * @param fmt Pointer to the format specifier structure.
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
 * @brief Parses and processes a conversion specifier in the format string.
 *
 * Attempts to parse the format starting at `%`, storing parsed data in `fmt`.
 * If parsing fails, prints the raw format substring instead. If parsing
 * succeeds, delegates output to `parse_and_handle_specifier`.
 *
 * @param format Pointer to the current format string position.
 * @param args Pointer to the variadic arguments list.
 * @param pf Pointer to the print state tracker.
 * 
 * @see reset_fmt
 * @see setup_format
 * @see parse_and_handle_specifier
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
	if (pf->write_error != 0 || pf->malloc_error != 0)
		return ;
}

/**
 * @brief Processes an entire format string for `ft_printf`.
 *
 * Iterates through the format string and processes each character. When
 * encountering a `%`, parses the format specifier and prints the
 * corresponding argument. Normal characters are printed directly.
 *
 * @param format The format string passed to `ft_printf`.
 * @param args The variadic argument list.
 * @param pf Pointer to the print state tracker.
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
