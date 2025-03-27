/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:49:29 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:02 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file handle_precision_int.c
 * @brief Precision formatting for integers in ft_printf.
 *
 * This file provides helper functions to format integer-like values
 * (including `d`, `i`, `x`, `X`, and `u`) according to the precision
 * specified in the format string. It includes logic for adding leading
 * zeros and handling edge cases like zero values with zero precision.
 *
 * @author nlouis
 * @date 2024/11/08
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Adds leading zero padding for integer precision formatting.
 *
 * If the format precision is greater than the number length, this function
 * allocates a new string and fills it with the appropriate number of
 * leading zeros. Negative numbers are handled by keeping the minus sign
 * at the front.
 *
 * @param pf Pointer to the printf state structure.
 * @param str The original number string.
 * @param len Pointer to the current string length (updated if changed).
 * @param is_neg Whether the number is negative (1 if true, 0 if false).
 *
 * @return A newly allocated and padded string, or NULL on allocation error.
 * 
 * @see ft_calloc
 * @see ft_memset
 * @see ft_strlcpy
 * @ingroup ft_printf
 */
static char	*apply_precision_zero_padding(t_pf *pf, char *str, int *len,
															int is_neg)
{
	int		zero_padding;
	char	*new_str;

	if (pf->fmt->precision > *len - is_neg)
	{
		zero_padding = pf->fmt->precision - (*len - is_neg);
		new_str = ft_calloc(pf->fmt->precision + is_neg + 1, sizeof(char));
		if (!new_str)
		{
			pf->malloc_error = 1;
			free(str);
			return (NULL);
		}
		if (is_neg == 1)
			new_str[0] = '-';
		ft_memset(new_str + is_neg, '0', zero_padding);
		ft_strlcpy(new_str + is_neg + zero_padding, str + is_neg,
			(*len - is_neg) + 1);
		*len = pf->fmt->precision + is_neg;
		free(str);
		return (new_str);
	}
	return (str);
}

/**
 * @brief Handles special case when precision is 0 and value is 0.
 *
 * If the value is `"0"` and precision is zero, this function decides whether
 * to keep the `"0"` (if `#` flag is set and it's a hex format), or replace
 * it with an empty string.
 *
 * @param len Pointer to the string length to update.
 * @param str The input string ("0").
 * @param pf Pointer to the printf state structure.
 *
 * @return A valid string to print (may be ""), or NULL on allocation failure.
 * 
 * @see ft_strdup
 * @ingroup ft_printf
 */
static char	*handle_hashflag_zero_prec(int *len, char *str, t_pf *pf)
{
	if ((pf->fmt->flags & FLAG_HASH)
		&& (pf->fmt->specifier == 'x' || pf->fmt->specifier == 'X'))
	{
		*len = 1;
		return (str);
	}
	else
	{
		free(str);
		*len = 0;
		str = ft_strdup("");
		if (!str)
		{
			pf->malloc_error = 1;
			return (NULL);
		}
		return (str);
	}
}

/**
 * @brief Applies precision formatting rules to integer output.
 *
 * This is the main interface for formatting integers according to precision.
 * It handles negative numbers, zero value suppression, and applies leading
 * zeros when necessary.
 *
 * @param fmt Pointer to the current format specification.
 * @param str The numeric string to format (must be malloc'd).
 * @param len Pointer to the string length (updated if changed).
 * @param pf Pointer to the printf state structure.
 *
 * @return The updated (and possibly reallocated) string, or NULL on error.
 *
 * @see apply_precision_zero_padding
 * @see handle_hashflag_zero_prec
 * @ingroup ft_printf
 */
char	*handle_precision_int(t_fmt *fmt, char *str, int *len, t_pf *pf)
{
	int	is_negative;

	if (str == NULL || fmt->precision == -1)
		return (str);
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
		is_negative = (str[0] == '-');
	else
		is_negative = 0;
	if (*str == '0' && str[1] == '\0')
	{
		if (fmt->precision == 0)
		{
			str = handle_hashflag_zero_prec(len, str, pf);
			if (!str)
				return (NULL);
		}
	}
	str = apply_precision_zero_padding(pf, str, len, is_negative);
	if (!str)
		return (NULL);
	return (str);
}
