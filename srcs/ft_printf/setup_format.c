/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:28:23 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:29 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file setup_format.c
 * @brief Parses the format specifier for ft_printf.
 *
 * This file contains helper functions used to parse format strings
 * for the custom `ft_printf` implementation. It extracts flags, width,
 * precision, and specifier from the format string into a `t_fmt` struct.
 *
 * These values are later used by `ft_printf` handlers to properly format
 * the output.
 *
 * @author nlouis
 * @date 2024/10/15
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Parses formatting flags from the format string.
 *
 * Sets appropriate bits in `fmt->flags` for each flag found:
 * `#`, `0`, `-`, `+`, or space. Advances the format pointer.
 *
 * @param format Pointer to the format string pointer.
 * @param fmt Pointer to the format specification struct.
 * 
 * @see is_valid_flag
 * @ingroup ft_printf
 */
static void	parse_flags(const char **format, t_fmt *fmt)
{
	while (**format && is_valid_flag(**format))
	{
		if (**format == '#')
			fmt->flags |= FLAG_HASH;
		else if (**format == '0')
			fmt->flags |= FLAG_ZERO;
		else if (**format == '-')
			fmt->flags |= FLAG_MINUS;
		else if (**format == '+')
			fmt->flags |= FLAG_PLUS;
		else if (**format == ' ')
			fmt->flags |= FLAG_SPACE;
		(*format)++;
	}
}

/**
 * @brief Parses the width specifier from the format string.
 *
 * Reads the width value and stores it in `fmt->width`. Advances the
 * format pointer past the digits.
 *
 * @param format Pointer to the format string pointer.
 * @param fmt Pointer to the format specification struct.
 * 
 * @see ft_atoi
 * @see ft_isdigit
 * @ingroup ft_printf
 */
static void	parse_width(const char **format, t_fmt *fmt)
{
	fmt->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

/**
 * @brief Parses the precision specifier from the format string.
 *
 * If a `.` is encountered, this function sets `fmt->precision` to the
 * specified value. If the dot is not followed by digits, precision
 * is set to 0.
 *
 * @param format Pointer to the format string pointer.
 * @param fmt Pointer to the format specification struct.
 * 
 * @see ft_atoi
 * @see ft_isdigit
 * @ingroup ft_printf
 */
static void	parse_precision(const char **format, t_fmt *fmt)
{
	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			fmt->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else
			fmt->precision = 0;
	}
}

/**
 * @brief Parses the conversion specifier from the format string.
 *
 * Validates the next character as a format specifier (e.g., `d`, `s`, `x`).
 * If valid, sets `fmt->specifier`. Otherwise returns -1.
 *
 * @param format Pointer to the format string pointer.
 * @param fmt Pointer to the format specification struct.
 * @return 0 on success, -1 on failure.
 * 
 * @see ft_strchr
 * @ingroup ft_printf
 */
static int	parse_specifier(const char **format, t_fmt *fmt)
{
	if (**format == '\0')
		return (-1);
	if (ft_strchr("cspdiuxX%", **format))
	{
		fmt->specifier = **format;
		(*format)++;
		return (0);
	}
	fmt->specifier = '\0';
	return (-1);
}

/**
 * @brief Parses a full format specifier and stores it in a t_fmt struct.
 *
 * This function parses flags, width, precision, and the conversion
 * specifier in order. It returns -1 if the specifier is invalid.
 *
 * @param format Pointer to the format string pointer.
 * @param fmt Pointer to the format specification struct.
 * @return 0 on success, -1 if specifier is invalid.
 * 
 * @see parse_flags
 * @see parse_width
 * @see parse_precision
 * @see parse_specifier
 * @ingroup ft_printf
 */
int	setup_format(const char **format, t_fmt *fmt)
{
	parse_flags(format, fmt);
	parse_width(format, fmt);
	parse_precision(format, fmt);
	if (parse_specifier(format, fmt) == -1)
		return (-1);
	return (0);
}
