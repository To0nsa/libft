/**
 * @file handle_precision_int.c
 * @brief Precision formatting for integer values in `ft_printf`.
 *
 * @details
 * This file provides helpers to apply precision rules to numeric output
 * (for `%d`, `%i`, `%u`, `%x`, `%X`). It handles leading zeros, negative
 * signs, and special behaviors like empty output when the value is zero and
 * the precision is also zero.
 *
 * These functions operate in conjunction with the `t_fmt` format specifier
 * and update internal state using `t_pf`.
 *
 * @author Toonsa
 * @date 2024/11/08
 * @ingroup ft_printf
 */

#include "libft.h"

/**
 * @brief Pads integer string with leading zeros to match precision.
 *
 * If precision is greater than the number of digits, this function inserts
 * leading zeros. Handles negative numbers by preserving the `-` sign at the
 * start of the result.
 *
 * @param pf Pointer to the ft_printf global state.
 * @param str Malloc’d number string (will be freed if changed).
 * @param len Pointer to length of string (updated if modified).
 * @param is_neg 1 if the number is negative (i.e., has `-` prefix), 0 otherwise.
 *
 * @return A new malloc’d string with applied precision, or `NULL` on error.
 *
 * @see ft_calloc
 * @see ft_memset
 * @see ft_strlcpy
 * @ingroup ft_printf
 */
static char* apply_precision_zero_padding(t_pf* pf, char* str, int* len,
                                          int is_neg)
{
	int   zero_padding;
	char* new_str;

	if (pf->fmt->precision > *len - is_neg)
	{
		zero_padding = pf->fmt->precision - (*len - is_neg);
		new_str      = ft_calloc(pf->fmt->precision + is_neg + 1, sizeof(char));
		if (!new_str)
		{
			pf->malloc_error = 1;
			free(str);
			return (NULL);
		}
		if (is_neg)
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
 * @brief Handles edge case for `"0"` with precision set to 0.
 *
 * When precision is explicitly 0 and the value is also `0`, the result
 * is normally an empty string unless the `#` flag is set for hex.
 *
 * @param len Pointer to the string length (will be updated).
 * @param str The current numeric string.
 * @param pf Pointer to the ft_printf global state.
 *
 * @return New string or NULL on allocation failure.
 *
 * @note Returns `"(null)"` if memory allocation fails.
 * @ingroup ft_printf
 */
static char* handle_hashflag_zero_prec(int* len, char* str, t_pf* pf)
{
	if ((pf->fmt->flags & FLAG_HASH) &&
	    (pf->fmt->specifier == 'x' || pf->fmt->specifier == 'X'))
	{
		*len = 1;
		return (str);
	}
	else
	{
		free(str);
		*len = 0;
		str  = ft_strdup("");
		if (!str)
		{
			pf->malloc_error = 1;
			return (NULL);
		}
		return (str);
	}
}

/**
 * @brief Applies precision formatting to a numeric string.
 *
 * This is the main function used for formatting `%d`, `%i`, `%u`, `%x`, `%X`
 * according to the precision field of the format string. It takes care of:
 * - Adding leading zeros
 * - Skipping output for `"0"` when precision is 0
 * - Handling negative sign in integer
 *
 * @param fmt Current format specifier.
 * @param str Numeric string to process (must be malloc’d).
 * @param len Pointer to the string length (updated).
 * @param pf Pointer to the ft_printf global state.
 *
 * @return The updated string (malloc’d), or `NULL` on error.
 *
 * @see apply_precision_zero_padding
 * @see handle_hashflag_zero_prec
 * @ingroup ft_printf
 */
char* handle_precision_int(t_fmt* fmt, char* str, int* len, t_pf* pf)
{
	int is_negative;

	if (str == NULL || fmt->precision == -1)
		return (str);
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
		is_negative = (str[0] == '-');
	else
		is_negative = 0;
	if (*str == '0' && str[1] == '\0' && fmt->precision == 0)
	{
		str = handle_hashflag_zero_prec(len, str, pf);
		if (!str)
			return (NULL);
	}
	str = apply_precision_zero_padding(pf, str, len, is_negative);
	if (!str)
		return (NULL);
	return (str);
}
