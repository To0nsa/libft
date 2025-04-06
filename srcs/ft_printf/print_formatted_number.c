/**
 * @file print_formatted_number.c
 * @brief Handles formatting and output of integers in `ft_printf`.
 *
 * @details
 * This module formats and prints integer-based conversions (`%d`, `%i`, `%u`,
 * `%x`, `%X`) according to the format flags provided:
 * - Sign display (`+`, space)
 * - Alternative form (`#`)
 * - Padding (`0`, `-`)
 * - Precision control
 *
 * It builds a final formatted string with prefixes and signs,
 * calculates padding, and outputs everything while tracking
 * write or allocation failures.
 *
 * @author Toonsa
 * @date 2024/10/29
 * @ingroup ft_printf
 */

#include "libft.h"

/**
 * @brief Prepends a sign character (`+` or space) to a number string.
 *
 * @details
 * Allocates and returns a new string with the specified sign inserted
 * at the beginning. Frees the old string. Used for `%d` / `%i` formatting.
 *
 * @param str The numeric string to modify (will be freed).
 * @param sign The character to prepend (`+` or `' '`).
 * @param pf Pointer to the printf context (for error tracking).
 *
 * @return Newly allocated string with prepended sign, or `NULL` on error.
 *
 * @see ft_strlcpy
 * @ingroup ft_printf
 */
static char* prepend_sign(char* str, char sign, t_pf* pf)
{
	int   len;
	char* new_str;

	if (!str)
		return (NULL);
	len     = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
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
 * @brief Applies `+`, space, and `#` flags to the formatted number.
 *
 * @details
 * Prepends signs or prefixes to the string depending on format specifier
 * and flags. Updates string length accordingly.
 *
 * @param pf The current printf state.
 * @param str Pointer to the number string (malloc'd).
 * @param len Pointer to its length (will be updated).
 *
 * @return Newly formatted string with all flags applied, or `NULL` on error.
 *
 * @see prepend_sign
 * @see prepend_alternative_form
 * @see requires_alternative_form
 * @see get_alternative_form_length
 * @ingroup ft_printf
 */
static char* apply_plus_space_hash_flags(t_pf* pf, char* str, int* len)
{
	if ((pf->fmt->specifier == 'd' || pf->fmt->specifier == 'i') &&
	    (pf->fmt->flags & FLAG_PLUS) && ft_isstrpositive(str))
	{
		str = prepend_sign(str, '+', pf);
		if (!str)
			return (NULL);
		(*len)++;
	}
	else if ((pf->fmt->specifier == 'd' || pf->fmt->specifier == 'i') &&
	         (pf->fmt->flags & FLAG_SPACE) && ft_isstrpositive(str))
	{
		str = prepend_sign(str, ' ', pf);
		if (!str)
			return (NULL);
		(*len)++;
	}
	if ((pf->fmt->flags & FLAG_HASH) &&
	    requires_alternative_form(pf->fmt->specifier, str))
	{
		str = prepend_alternative_form(str, pf->fmt->specifier, pf);
		if (!str)
			return (NULL);
		*len += get_alternative_form_length(pf->fmt->specifier);
	}
	return (str);
}

/**
 * @brief Writes the number string with left/right padding.
 *
 * @param pf The current printf context.
 * @param str The string to print.
 * @param padding Number of padding spaces.
 *
 * @see write_safely
 * @see print_padding
 * @ingroup ft_printf
 */
static void print_with_padding(t_pf* pf, char* str, int padding)
{
	if (!(pf->fmt->flags & FLAG_MINUS) && !(pf->fmt->flags & FLAG_ZERO))
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error)
			return;
	}
	write_safely(1, str, pf);
	if (pf->write_error)
		return;
	if (pf->fmt->flags & FLAG_MINUS)
	{
		print_padding(padding, ' ', pf);
		if (pf->write_error)
			return;
	}
}

/**
 * @brief Writes zero-padding and handles printing the sign first if needed.
 *
 * @param padding Amount of zeros to pad.
 * @param str_ptr Pointer to the string pointer (adjusted if sign is printed).
 * @param pf The printf state.
 *
 * @see write_char_safely
 * @ingroup ft_printf
 */
static void print_zero_padding_int(int padding, char** str_ptr, t_pf* pf)
{
	int sign;

	sign =
	    ((*str_ptr)[0] == '-' || (*str_ptr)[0] == '+' || (*str_ptr)[0] == ' ');
	if (padding <= 0)
		return;
	if (sign)
	{
		write_char_safely(1, **str_ptr, pf);
		if (pf->write_error)
			return;
		(*str_ptr)++;
	}
	while (padding--)
	{
		write_char_safely(1, '0', pf);
		if (pf->write_error)
			return;
	}
}

/**
 * @brief Final formatter and dispatcher for integer output.
 *
 * @details
 * This function prepares a number string for printing by applying:
 * - flags (`+`, ` `, `#`)
 * - width / zero-padding
 * - left/right alignment
 *
 * It prints the fully formatted number and handles memory cleanup.
 *
 * @param fmt The current format descriptor.
 * @param str Malloc'd number string to format.
 * @param len Initial string length.
 * @param pf The printf context for output state tracking.
 *
 * @ingroup ft_printf
 */
void print_formatted_number(t_fmt* fmt, char* str, int len, t_pf* pf)
{
	int   padding;
	char* formatted_str;
	char* temp_ptr;

	formatted_str = apply_plus_space_hash_flags(pf, str, &len);
	if (!formatted_str)
		return;
	padding  = handle_width(fmt, len);
	temp_ptr = formatted_str;
	if ((fmt->flags & FLAG_ZERO) && !(fmt->flags & FLAG_MINUS) &&
	    fmt->precision < 0)
	{
		print_zero_padding_int(padding, &temp_ptr, pf);
		if (pf->write_error)
			return;
		write_safely(1, temp_ptr, pf);
	}
	else
		print_with_padding(pf, formatted_str, padding);
	if (!pf->write_error)
		free(formatted_str);
}
