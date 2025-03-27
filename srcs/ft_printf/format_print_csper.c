/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_print_csper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:08:57 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:37:42 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file format_print_csper.c
 * @brief Handles printing of %c, %s, and %% specifiers for ft_printf.
 *
 * This file contains the formatting and output logic for character (`%c`),
 * string (`%s`), and percent sign (`%%`) specifiers, including alignment
 * and padding based on formatting flags.
 *
 * Each function uses the `t_fmt` structure to determine formatting options
 * and the `t_pf` structure to manage output state and errors.
 *
 * @author nlouis
 * @date 2024/11/08
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Formats and prints the '%%' specifier.
 *
 * Handles printing a literal percent sign with optional width and padding.
 *
 * @param fmt Pointer to the formatting structure.
 * @param pf Pointer to the printf state structure.
 *
 * @note Uses zero-padding if FLAG_ZERO is set, and handles alignment
 *       with FLAG_MINUS. Updates write_error if a write fails.
 * 
 * @see print_padding
 * @see write_char_safely
 * @see handle_width
 * @ingroup ft_printf
 */
void	format_and_print_percent(t_fmt *fmt, t_pf *pf)
{
	int		padding;
	char	pad_char;

	if (fmt->flags & FLAG_ZERO)
		pad_char = '0';
	else
		pad_char = ' ';
	padding = handle_width(fmt, 1);
	if (!(fmt->flags & FLAG_MINUS))
	{
		print_padding(padding, pad_char, pf);
		if (pf->write_error != 0)
			return ;
	}
	write_char_safely(1, '%', pf);
	if (pf->write_error != 0)
		return ;
	if (fmt->flags & FLAG_MINUS)
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error != 0)
			return ;
	}
}

/**
 * @brief Formats and prints a character (%c).
 *
 * Retrieves a character from the variadic arguments and prints it with
 * optional padding and alignment.
 *
 * @param fmt Pointer to the formatting structure.
 * @param args Pointer to the variadic argument list.
 * @param pf Pointer to the printf state structure.
 *
 * @note Handles left or right alignment based on FLAG_MINUS.
 * @see write_char_safely
 * @see handle_width
 * @see print_padding
 * @ingroup ft_printf
 */
void	format_and_print_c(t_fmt *fmt, va_list *args, t_pf *pf)
{
	char	c;
	int		padding;

	c = va_arg(*args, int);
	padding = handle_width(fmt, 1);
	if (!(fmt->flags & FLAG_MINUS))
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error != 0)
			return ;
	}
	write_char_safely(1, c, pf);
	if (pf->write_error != 0)
		return ;
	if (fmt->flags & FLAG_MINUS)
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error != 0)
			return ;
	}
}

/**
 * @brief Formats and prints a string (%s).
 *
 * Retrieves a string from the variadic arguments and prints it with
 * optional width, precision, and alignment.
 *
 * @param fmt Pointer to the formatting structure.
 * @param args Pointer to the variadic argument list.
 * @param pf Pointer to the printf state structure.
 *
 * @note Precision truncates the string if specified. If the string is NULL,
 *       prints "(null)". Alignment is based on FLAG_MINUS.
 * 
 * @see handle_precision_s
 * @see handle_width
 * @see print_padding
 * @see write_safely_len
 * @ingroup ft_printf
 */
void	format_and_print_s(t_fmt *fmt, va_list *args, t_pf *pf)
{
	char	*str;
	size_t	len;
	int		padding;

	str = va_arg(*args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	len = handle_precision_s(fmt, len);
	padding = handle_width(fmt, len);
	if (!(fmt->flags & FLAG_MINUS))
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error != 0)
			return ;
	}
	write_safely_len(1, str, len, pf);
	if (pf->write_error != 0)
		return ;
	if (fmt->flags & FLAG_MINUS)
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error != 0)
			return ;
	}
}
