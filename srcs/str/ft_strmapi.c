/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:47:08 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:30:17 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strmapi()
 * Applies a function to each character of a string to create a new string.
 *
 * @s: The input string.
 * @f: The function to apply, taking the index and the character as arguments.
 *
 * Returns: A newly allocated string resulting from applications of @f,
 *			or NULL if allocation fails or if @s or @f is NULL.
 *
 * Notes:
 * - The original string is not modified.
 * - The resulting string is null-terminated.
 * - Useful for mapping transformations (e.g., to uppercase with index logic).
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
