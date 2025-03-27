/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:19:58 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:37:52 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_printf.c
 * @brief Implementation of a custom printf-like function.
 *
 * This file defines the main entry point for `ft_printf`, a simplified
 * version of the standard `printf` function. It supports formatted
 * output with support for flags, width, precision, and various format
 * specifiers. This function allocates and manages internal formatting
 * structures and handles errors related to memory or I/O.
 *
 * @author nlouis
 * @date 2024/10/15
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Custom implementation of the standard `printf`.
 *
 * This function parses a format string and prints formatted output to
 * standard output (fd = 1). It supports a subset of standard format
 * specifiers (e.g., %d, %s, %x, etc.).
 *
 * Internally, it initializes a formatting context (`t_pf`) and parses
 * the format string using `process_format_string`. Memory is dynamically
 * allocated for the formatting structures, and errors are tracked
 * (e.g., malloc failure or write failure).
 *
 * @param format The format string to be parsed.
 * @param ...    Variadic arguments corresponding to format specifiers.
 *
 * @return The number of characters written on success, or -1 on error.
 *
 * @note This function must be used with proper format and argument types.
 * @note Memory errors (e.g., malloc) or write errors will cause -1 return.
 *
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
	if (pf->malloc_error == 1 || pf->write_error == 1)
		error = -1;
	free(pf->fmt);
	free(pf);
	if (error == -1)
		return (error);
	else
		return (total);
}
