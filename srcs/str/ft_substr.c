/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:48:53 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:34:09 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_substr()
 * Allocates and returns a substring from the string @s.
 *
 * @s: The source string.
 * @start: The start index of the substring in @s.
 * @len: The maximum number of characters to include in the substring.
 *
 * Returns: A newly allocated string containing the substring,
 *			or an empty string if @start is beyond the end of @s,
 *			or NULL if allocation fails.
 *
 * Notes:
 * - The substring is null-terminated.
 * - If @len extends past the end of @s, it is trimmed to fit.
 * - The caller is responsible for freeing the returned string.
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			str_len;
	size_t			max_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		substr = (char *)malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	max_len = str_len - start;
	if (max_len > len)
		max_len = len;
	substr = (char *)malloc((max_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, max_len + 1);
	return (substr);
}
