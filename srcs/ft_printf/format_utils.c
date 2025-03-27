/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:03:25 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:37:47 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file format_utils.c
 * @brief Utilities for handling padding, width, and precision in ft_printf.
 *
 * This file contains helper functions to handle field width, precision,
 * and padding logic for formatted output inside the ft_printf implementation.
 *
 * These utilities work with the format specification struct `t_fmt`
 * and update the global printf state in `t_pf`.
 *
 * @author nlouis
 * @date 2024/11/13
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Prints padding characters for formatting alignment.
 *
 * Writes a specified number of padding characters (e.g., spaces or zeros)
 * to the standard output using `write_char_safely`, updating the total
 * byte count in `t_pf`.
 *
 * @param padding Number of padding characters to print.
 * @param pad_char The character to use for padding.
 * @param pf Pointer to the printf state structure.
 *
 * @note If a write error occurs, `pf->write_error` is set.
 * 
 * @see write_char_safely
 * @ingroup ft_printf
 */
void	print_padding(int padding, char pad_char, t_pf *pf)
{
	if (padding <= 0)
		return ;
	while (padding > 0)
	{
		write_char_safely(1, pad_char, pf);
		if (pf->write_error != 0)
			return ;
		padding--;
	}
}

/**
 * @brief Adjusts string length based on precision.
 *
 * Used for string (`%s`) formatting to truncate the output to match
 * the given precision if specified.
 *
 * @param fmt Pointer to the format specifier struct.
 * @param len The original length of the string.
 *
 * @return The adjusted length, truncated to precision if applicable.
 * 
 * @ingroup ft_printf
 */
int	handle_precision_s(t_fmt *fmt, int len)
{
	if (fmt->precision >= 0 && fmt->precision < len)
		len = fmt->precision;
	return (len);
}

/**
 * @brief Computes the padding needed for width formatting.
 *
 * Calculates how many characters should be added to satisfy the
 * field width requirement for the current formatted argument.
 *
 * @param fmt Pointer to the format specifier struct.
 * @param len The length of the content to be printed.
 *
 * @return The number of padding characters required.
 *         Returns 0 if content is already wide enough.
 * 
 * @ingroup ft_printf
 */
int	handle_width(t_fmt *fmt, size_t len)
{
	int	padding;

	padding = fmt->width - len;
	if (padding < 0)
		padding = 0;
	return (padding);
}
