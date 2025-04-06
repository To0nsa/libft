/**
 * @file format_and_print_p.c
 * @brief Handles `%p` format specifier for ft_printf.
 *
 * @details
 * This file provides the implementation for printing pointer values
 * using the `%p` format in `ft_printf`. It handles:
 * - Null pointer printing as `(nil)`
 * - Hexadecimal conversion of pointer values
 * - Padding and precision based on format flags
 *
 * @author Toonsa
 * @date 2024/10/30
 * @ingroup ft_printf
 */

#include "libft.h"

/**
 * @brief Prints the pointer string with formatting and padding.
 *
 * @details
 * This function applies precision and width formatting to the
 * pointer string `str`, processes spacing or alignment flags,
 * and prints the formatted result. It frees the input string
 * once printed.
 *
 * @param fmt Format descriptor (flags, width, precision).
 * @param str String representation of the pointer.
 * @param pf Pointer to print context (error and length tracker).
 *
 * @see handle_precision_p
 * @see handle_width
 * @see handle_space_flag_p
 * @see handle_minus_flag_p
 * @see print_right_aligned_p
 * @ingroup ft_printf
 */
static void print_with_padding(t_fmt* fmt, char* str, t_pf* pf)
{
	int padding;
	int len;

	len = ft_strlen(str);
	if (fmt->precision > len)
	{
		str = handle_precision_p(fmt, str, &len, pf);
		if (!str)
			return;
	}
	padding = handle_width(fmt, len);
	handle_space_flag_p(pf, &padding);
	if (pf->write_error)
		return;
	handle_minus_flag_p(str, padding, pf);
	if (pf->write_error)
		return;
	print_right_aligned_p(fmt, str, padding, pf);
	if (str)
		free(str);
}

/**
 * @brief Returns the default string for a NULL pointer.
 *
 * @details
 * Allocates and returns the literal string `(nil)` to represent
 * null pointers in `%p` format.
 *
 * @param pf Print state tracker to set malloc error flag if needed.
 * @return A newly allocated string or NULL on allocation failure.
 *
 * @see ft_strdup
 * @ingroup ft_printf
 */
static char* handle_null_ptr(t_pf* pf)
{
	char* str;

	str = ft_strdup("(nil)");
	if (!str)
		pf->malloc_error = 1;
	return (str);
}

/**
 * @brief Converts a pointer to a lowercase hexadecimal string.
 *
 * @details
 * Converts the pointer address to a lowercase hexadecimal string,
 * prepends the `"0x"` prefix, and returns a newly allocated result.
 *
 * @param ptr Pointer to convert.
 * @param pf Print context to set error flag if needed.
 * @return Formatted pointer string or NULL on allocation error.
 *
 * @see ft_itoa_base
 * @see ft_strjoin
 * @ingroup ft_printf
 */
static char* convert_ptr_to_hex(void* ptr, t_pf* pf)
{
	char* str;
	char* result;

	str = ft_itoa_base((unsigned long long) ptr, 16, 0);
	if (!str)
	{
		pf->malloc_error = 1;
		return (NULL);
	}
	result = ft_strjoin("0x", str);
	free(str);
	if (!result)
		pf->malloc_error = 1;
	return (result);
}

/**
 * @brief Handles `%p` format specifier for ft_printf.
 *
 * @details
 * This function formats and prints a pointer argument. It converts the
 * pointer to hexadecimal, applies precision and alignment based on flags,
 * and handles the null case gracefully.
 *
 * @param fmt Format descriptor (flags, width, precision).
 * @param args Argument list (`va_list`) from `ft_printf`.
 * @param pf Print context structure.
 *
 * @see print_with_padding
 * @see handle_null_ptr
 * @see convert_ptr_to_hex
 * @ingroup ft_printf
 */
void format_and_print_p(t_fmt* fmt, va_list* args, t_pf* pf)
{
	void* ptr;
	char* str;

	ptr = va_arg(*args, void*);
	str = (ptr == NULL) ? handle_null_ptr(pf) : convert_ptr_to_hex(ptr, pf);
	if (!str)
		return;
	print_with_padding(fmt, str, pf);
}
