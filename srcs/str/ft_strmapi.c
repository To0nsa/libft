/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:47:08 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:11:16 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strmapi.c
 * @brief Applies a function to each character of a string.
 *
 * This file implements `ft_strmapi`, which creates a new string
 * resulting from the successive application of a function to
 * each character of the input string. The function receives the
 * index of the character as the first argument.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Applies a function to each character of a string to
 *        create a new string.
 *
 * Allocates a new string where each character is the result of
 * applying the given function `f` to the corresponding character
 * of the input string `s`. The function `f` receives the index
 * of each character as its first argument.
 *
 * @param s The original null-terminated string to map.
 * @param f The function to apply to each character, receiving
 *          the index and the character.
 * 
 * @return A new string with transformed characters, or NULL if
 *         allocation fails or if input is NULL.
 *
 * @note The returned string must be freed by the caller.
 *
 * @ingroup string_utils
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
