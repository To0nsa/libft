/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_alternative_form.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:15:56 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:19 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file printf_alternative_form.c
 * @brief Alternative form handling for hexadecimal output in ft_printf.
 *
 * This file contains helper functions to determine when to apply the
 * alternative form (`#`) and to prepend the appropriate prefix (`0x` or `0X`)
 * for hexadecimal output (`%x`, `%X`).
 *
 * It also provides a function to calculate the length of the added prefix.
 *
 * @author nlouis
 * @date 2024/10/30
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Checks if alternative form is required.
 *
 * Returns 1 if the alternative form (`#`) should be applied, meaning
 * the specifier is either 'x' or 'X' and the value is non-zero.
 *
 * @param specifier Format specifier character ('x' or 'X').
 * @param str String representation of the number.
 *
 * @return 1 if alternative form is needed, 0 otherwise.
 * 
 * @see ft_strcmp
 * @ingroup ft_printf
 */
int	requires_alternative_form(char specifier, char *str)
{
	if (str == NULL || str[0] == '\0' || ft_strcmp(str, "0") == 0)
		return (0);
	if (specifier == 'x' || specifier == 'X')
		return (1);
	return (0);
}

/**
 * @brief Prepends the alternative form prefix (0x or 0X).
 *
 * Allocates and returns a new string with the correct prefix added to
 * the input hexadecimal string, e.g., "0x1f" or "0X1F".
 *
 * @param str The original hexadecimal string (must be malloc'd).
 * @param specifier Format specifier, either 'x' or 'X'.
 * @param pf Pointer to the printf state structure (for error reporting).
 *
 * @return New string with prefix, or NULL on allocation failure.
 *         On failure, sets pf->malloc_error and frees the original string.
 * 
 * @see ft_strlen
 * @see ft_strcmp
 * @see strlcpy
 * @ingroup ft_printf
 */
char	*prepend_alternative_form(char *str, char specifier, t_pf *pf)
{
	int		len;
	char	*new_str;

	if (!str || str[0] == '\0' || ft_strcmp(str, "0") == 0)
		return (str);
	if (specifier != 'x' && specifier != 'X')
		return (str);
	len = ft_strlen(str);
	new_str = (char *)malloc(len + 3);
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
 * @brief Returns the length of the alternative form prefix.
 *
 * Used to adjust output length when alternative form is applied.
 * For hexadecimal, the prefix is 2 characters ("0x" or "0X").
 *
 * @param specifier Format specifier ('x' or 'X').
 * @return Length of prefix to apply (typically 2, or 0 if not applicable).
 * 
 * @ingroup ft_printf
 */
int	get_alternative_form_length(char specifier)
{
	if (specifier == 'x' || specifier == 'X')
		return (2);
	return (0);
}
