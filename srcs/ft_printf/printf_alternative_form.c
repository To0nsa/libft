/**
 * @file printf_alternative_form.c
 * @brief Handles the `#` flag for hexadecimal output in ft_printf.
 *
 * @details
 * This module provides support for the alternative form (`#`) used with
 * `%x` and `%X` format specifiers in `ft_printf`.
 *
 * It defines:
 * - Detection of when to apply the prefix.
 * - Generation of prefixed hexadecimal strings (`0x` / `0X`).
 * - Calculation of the prefix length for padding purposes.
 *
 * @author Toonsa
 * @date 2024/10/30
 * @ingroup ft_printf
 */

#include "libft.h"

/**
 * @brief Checks whether the alternative form (`#`) should be applied.
 *
 * @details
 * Alternative form is only applied if the specifier is `'x'` or `'X'` and
 * the value is non-zero (e.g., not `"0"`).
 *
 * @param specifier The format specifier character (`x` or `X`).
 * @param str String representation of the value to print.
 *
 * @return 1 if prefix should be applied, 0 otherwise.
 *
 * @ingroup ft_printf
 */
int requires_alternative_form(char specifier, char* str)
{
	if (!str || str[0] == '\0' || ft_strcmp(str, "0") == 0)
		return (0);
	if (specifier == 'x' || specifier == 'X')
		return (1);
	return (0);
}

/**
 * @brief Prepends the `0x` or `0X` prefix to a hexadecimal string.
 *
 * @details
 * Allocates a new string containing the appropriate prefix followed by the
 * original string. Frees the original string and updates the printf context
 * if an allocation error occurs.
 *
 * @param str The original hexadecimal string (must be malloc'd).
 * @param specifier Either `'x'` or `'X'`, determines the prefix casing.
 * @param pf Pointer to the printf context for error tracking.
 *
 * @return A newly allocated string with prefix, or NULL on error.
 *
 * @see ft_strlcpy
 * @ingroup ft_printf
 */
char* prepend_alternative_form(char* str, char specifier, t_pf* pf)
{
	int   len;
	char* new_str;

	if (!str || str[0] == '\0' || ft_strcmp(str, "0") == 0)
		return (str);
	if (specifier != 'x' && specifier != 'X')
		return (str);
	len     = ft_strlen(str);
	new_str = malloc(len + 3);
	if (!new_str)
	{
		pf->malloc_error = 1;
		free(str);
		return (NULL);
	}
	new_str[0] = '0';
	new_str[1] = specifier;
	ft_strlcpy(new_str + 2, str, len + 1);
	free(str);
	return (new_str);
}

/**
 * @brief Returns the prefix length for `%x` and `%X` when using `#` flag.
 *
 * @details
 * The prefix for alternative hexadecimal output is always two characters: `0x`
 * or `0X`.
 *
 * @param specifier The current format specifier.
 * @return Length of the prefix (2 if applicable, 0 otherwise).
 *
 * @ingroup ft_printf
 */
int get_alternative_form_length(char specifier)
{
	if (specifier == 'x' || specifier == 'X')
		return (2);
	return (0);
}
