/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:49:55 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:13 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file print_formatted_number.c
 * @brief Handles formatting and output of integers (d, i, u, x, X) in ft_printf.
 *
 * This file provides the logic to apply formatting flags (such as `+`, ` `, 
 * `#`, `0`, `-`), padding, precision, and alternative forms to numeric 
 * conversions in `ft_printf`. It handles sign management and safely writes 
 * output while tracking write or malloc errors.
 *
 * @author nlouis
 * @date 2024/10/29
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Adds a sign character to the beginning of a numeric string.
 *
 * Allocates a new string, prepends the sign (`+` or space), and copies the 
 * original numeric string. Frees the old string and returns the new one.
 *
 * @param str The numeric string to modify.
 * @param sign The character to prepend (`+` or space).
 * @param pf Pointer to the ft_printf context (for error handling).
 * @return Newly allocated string with prepended sign, or NULL on error.
 * 
 * @see ft_strlcpy
 * @ingroup ft_printf
 */
static char	*prepend_sign(char *str, char sign, t_pf *pf)
{
	int		len;
	char	*new_str;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	new_str = (char *)malloc(len + 2);
	if (new_str == NULL)
	{
		pf->malloc_error = 1;
		free(str);
		return (NULL);
	}
	new_str[0] = sign;
	ft_strlcpy(new_str + 1, str, len + 1);
	free(str);
	return (new_str);
}

/**
 * @brief Applies `+`, space, and `#` flags to a numeric string.
 *
 * Depending on the flags set in the format, this function prepends the
 * appropriate sign or prefix (e.g., "0x" for hex) to the number.
 *
 * @param pf Pointer to the printf state structure.
 * @param str The string representing the number.
 * @param len Pointer to the current length of the string (updated if changed).
 * 
 * @return Newly allocated string with applied flags, or NULL on error.
 * 
 * @see prepend_sign
 * @see prepend_alternative_form
 * @see get_alternative_form_length
 * @see requires_alternative_form
 * @ingroup ft_printf
 */
static char	*apply_plus_space_hash_flags(t_pf *pf, char *str, int *len)
{
	if ((pf->fmt->specifier == 'd' || pf->fmt->specifier == 'i')
		&& (pf->fmt->flags & FLAG_PLUS) && ft_isstrpositive(str))
	{
		str = prepend_sign(str, '+', pf);
		if (str == NULL)
			return (NULL);
		(*len)++;
	}
	else if ((pf->fmt->specifier == 'd' || pf->fmt->specifier == 'i')
		&& (pf->fmt->flags & FLAG_SPACE) && ft_isstrpositive(str))
	{
		str = prepend_sign(str, ' ', pf);
		if (str == NULL)
			return (NULL);
		(*len)++;
	}
	if ((pf->fmt->flags & FLAG_HASH)
		&& requires_alternative_form(pf->fmt->specifier, str))
	{
		str = prepend_alternative_form(str, pf->fmt->specifier, pf);
		if (str == NULL)
			return (NULL);
		*len += get_alternative_form_length(pf->fmt->specifier);
	}
	return (str);
}

/**
 * @brief Prints padding and the numeric string, considering alignment flags.
 *
 * Adds left or right padding based on the `-` flag, and prints the number
 * string in between.
 *
 * @param pf Pointer to the printf state structure.
 * @param str The formatted numeric string.
 * @param padding Number of spaces to pad.
 * 
 * @see print_padding
 * @see write_safely
 * @ingroup ft_printf
 */
static void	print_with_padding(t_pf *pf, char *str, int padding)
{
	if (!(pf->fmt->flags & FLAG_MINUS) && !(pf->fmt->flags & FLAG_ZERO))
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error != 0)
			return ;
	}
	write_safely(1, str, pf);
	if (pf->write_error != 0)
		return ;
	if (pf->fmt->flags & FLAG_MINUS)
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error != 0)
			return ;
	}
}

/**
 * @brief Prints zero padding for integers, handling sign placement.
 *
 * If a sign is present (`+`, `-`, or space), it is printed first. Then the 
 * required number of `0` characters is printed.
 *
 * @param padding The number of zeros to print.
 * @param str_ptr Pointer to the number string (sign may be skipped).
 * @param pf Pointer to the printf state structure.
 * 
 * @see write_char_safely
 * @ingroup ft_printf
 */
static void	print_zero_padding_int(int padding, char **str_ptr, t_pf *pf)
{
	int		sign;
	char	pad_char;

	pad_char = '0';
	sign = ((*str_ptr)[0] == '-' || (*str_ptr)[0] == '+'
			|| (*str_ptr)[0] == ' ');
	if (padding <= 0)
		return ;
	if (pad_char == '0' && sign == 1)
	{
		write_char_safely(1, (*str_ptr)[0], pf);
		if (pf->write_error != 0)
			return ;
		*str_ptr += 1;
	}
	while (padding > 0)
	{
		write_char_safely(1, pad_char, pf);
		if (pf->write_error != 0)
			return ;
		padding--;
	}
}

/**
 * @brief Formats and prints an integer with padding, precision, and flags.
 *
 * This function prepares the number string by applying format flags 
 * (`+`, `#`, etc.), adjusts the padding, and then prints the result 
 * using the correct alignment and padding method.
 *
 * @param fmt Pointer to the current format specification.
 * @param str String representation of the number (must be malloc'd).
 * @param len Length of the input string.
 * @param pf Pointer to the printf state structure.
 * 
 * @see apply_plus_space_hash_flags
 * @see handle_width
 * @see print_with_padding
 * @see print_zero_padding_int
 * @ingroup ft_printf
 */
void	print_formatted_number(t_fmt *fmt, char *str, int len, t_pf *pf)
{
	int		padding;
	char	*formatted_str;
	char	*temp_ptr;

	formatted_str = apply_plus_space_hash_flags(pf, str, &len);
	if (formatted_str == NULL)
		return ;
	padding = handle_width(fmt, len);
	temp_ptr = formatted_str;
	if ((fmt->flags & FLAG_ZERO) && !(fmt->flags & FLAG_MINUS)
		&& fmt->precision < 0)
	{
		print_zero_padding_int(padding, &temp_ptr, pf);
		if (pf->write_error != 0)
			return ;
		write_safely(1, temp_ptr, pf);
		if (pf->write_error != 0)
			return ;
	}
	else
		print_with_padding(pf, formatted_str, padding);
	if (pf->write_error != 0)
		return ;
	free(formatted_str);
}
