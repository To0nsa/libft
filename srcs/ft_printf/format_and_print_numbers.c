/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_and_print_numbers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:54:20 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:37:32 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file format_and_print_numbers.c
 * @brief Handles numeric specifiers for ft_printf.
 *
 * This file provides the implementation for handling integer (`%d`, `%i`),
 * unsigned (`%u`), and hexadecimal (`%x`, `%X`) format specifiers for
 * `ft_printf`. Each function retrieves the correct argument, applies
 * precision formatting, and prints the number according to the provided
 * format descriptor.
 *
 * @author nlouis
 * @date 2024/10/29
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Handles `%d` and `%i` format specifiers for ft_printf.
 *
 * Converts an integer to string using `ft_itoa`, applies precision
 * handling via `handle_precision_int`, and prints the formatted result.
 *
 * Sets the malloc error flag in `pf` if memory allocation fails.
 *
 * @param fmt Format descriptor containing flags, width, and precision.
 * @param args Pointer to the va_list containing the argument.
 * @param pf Pointer to the ft_printf state structure.
 *
 * @see ft_itoa
 * @see handle_precision_int
 * @see print_formatted_number
 * @ingroup ft_printf
 */
void	format_and_print_id(t_fmt *fmt, va_list *args, t_pf *pf)
{
	int				num;
	char			*str;
	int				len;

	num = va_arg(*args, int);
	str = ft_itoa(num);
	if (str == NULL)
	{
		pf->malloc_error = 1;
		return ;
	}
	len = ft_strlen(str);
	str = handle_precision_int(fmt, str, &len, pf);
	if (str == NULL)
		return ;
	print_formatted_number(fmt, str, len, pf);
	if (pf->write_error != 0)
		return ;
}

/**
 * @brief Handles `%u` format specifier for ft_printf.
 *
 * Converts an unsigned integer to string using `ft_utoa`, applies
 * precision handling, and prints the result.
 *
 * @param fmt Format descriptor containing flags, width, and precision.
 * @param args Pointer to the va_list containing the argument.
 * @param pf Pointer to the ft_printf state structure.
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
	int				len;

	num = va_arg(*args, unsigned int);
	str = ft_utoa(num);
	if (str == NULL)
		return ;
	len = ft_strlen(str);
	str = handle_precision_int(fmt, str, &len, pf);
	if (str == NULL)
		return ;
	print_formatted_number(fmt, str, len, pf);
	if (pf->write_error != 0)
		return ;
}

/**
 * @brief Handles `%x` and `%X` format specifiers for ft_printf.
 *
 * Converts an unsigned integer to a hexadecimal string using
 * `ft_itoa_base`, applies precision formatting, and prints the result.
 *
 * @param fmt Format descriptor with formatting flags and specifier.
 * @param args Pointer to the va_list containing the argument.
 * @param upper Whether to print in uppercase (1 for `%X`, 0 for `%x`).
 * @param pf Pointer to the ft_printf state structure.
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
	if (str == NULL)
		return ;
	len = ft_strlen(str);
	str = handle_precision_int(fmt, str, &len, pf);
	if (str == NULL)
		return ;
	print_formatted_number(fmt, str, len, pf);
	if (pf->write_error != 0)
		return ;
}
