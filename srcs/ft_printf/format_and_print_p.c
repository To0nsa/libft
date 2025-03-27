/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_and_print_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:10:58 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:37:37 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file format_and_print_p.c
 * @brief Handles %p format specifier for ft_printf.
 *
 * This file implements formatting and printing of pointer values for
 * the `%p` format specifier used in `ft_printf`. It includes conversion
 * to hexadecimal representation with the `"0x"` prefix, and manages
 * optional padding and precision.
 *
 * @author nlouis
 * @date 2024/10/30
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Prints the pointer string with formatting and padding.
 *
 * Applies precision and width formatting to the pointer string `str`,
 * handles space and minus flags, and writes the formatted result to
 * standard output. Updates the write error and total written state
 * via the `t_pf` struct.
 *
 * @param fmt The format descriptor.
 * @param str The string representation of the pointer.
 * @param pf The print context (for tracking errors and total length).
 * 
 * @see handle_precision_p
 * @see handle_width
 * @see handle_space_flag_p
 * @see handle_minus_flag_p
 * @see print_right_aligned_p
 * @ingroup ft_printf
 */
static void	print_with_padding(t_fmt *fmt, char *str, t_pf *pf)
{
	int		padding;
	int		len;

	len = ft_strlen(str);
	if (fmt->precision > len)
	{
		str = handle_precision_p(fmt, str, &len, pf);
		if (!str)
			return ;
	}
	padding = handle_width(fmt, len);
	handle_space_flag_p(pf, &padding);
	if (pf->write_error != 0)
		return ;
	handle_minus_flag_p(str, padding, pf);
	if (pf->write_error != 0)
		return ;
	print_right_aligned_p(fmt, str, padding, pf);
	if (pf->write_error != 0)
		return ;
	if (str != NULL)
		free(str);
}

/**
 * @brief Returns the default string for NULL pointer.
 *
 * Creates a string `"(nil)"` to represent a null pointer in `%p`
 * formatting.
 *
 * @param pf Pointer to the ft_printf state tracker.
 * @return A newly allocated string or NULL on malloc error.
 * 
 * @see ft_strdup
 * @ingroup ft_printf
 */
static char	*handle_null_ptr(t_pf *pf)
{
	char	*str;

	str = ft_strdup("(nil)");
	if (str == NULL)
		pf->malloc_error = 1;
	return (str);
}

/**
 * @brief Converts a pointer to a hexadecimal string with "0x" prefix.
 *
 * Casts the pointer to `unsigned long long` and converts it to a
 * lowercase hexadecimal string. Prepends `"0x"` and returns the new
 * string. On memory failure, sets `pf->malloc_error`.
 *
 * @param ptr The pointer to convert.
 * @param pf Pointer to the print state structure.
 * @return A newly allocated formatted string or NULL on failure.
 * 
 * @see ft_itoa_base
 * @see ft_strjoin
 * @ingroup ft_printf
 */
static char	*convert_ptr_to_hex(void *ptr, t_pf *pf)
{
	char	*str;
	char	*new_str;

	str = ft_itoa_base((unsigned long long)ptr, 16, 0);
	if (str == NULL)
	{
		pf->malloc_error = 1;
		return (NULL);
	}
	new_str = ft_strjoin("0x", str);
	free(str);
	if (new_str == NULL)
		pf->malloc_error = 1;
	return (new_str);
}

/**
 * @brief Formats and prints a pointer argument (`%p`).
 *
 * Converts the given pointer to a hex string and applies padding,
 * precision, and flags based on the format descriptor. Handles NULL
 * pointers with a special output. Tracks all errors via `t_pf`.
 *
 * @param fmt The format specification (flags, width, precision).
 * @param args The argument list (from va_list).
 * @param pf The print state tracker for error handling and length.
 * 
 * @see print_with_padding
 * @see handle_null_ptr
 * @see convert_ptr_to_hex
 * @ingroup ft_printf
 */
void	format_and_print_p(t_fmt *fmt, va_list *args, t_pf *pf)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(*args, void *);
	if (!ptr)
		str = handle_null_ptr(pf);
	else
		str = convert_ptr_to_hex(ptr, pf);
	if (str == NULL)
		return ;
	print_with_padding(fmt, str, pf);
	if (pf->write_error != 0)
		return ;
}
