/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:47:53 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:31:44 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strnstr()
 * Locates the first occurrence of a substring within a string,
 * searching at most len characters.
 *
 * @big: The string to search in.
 * @little: The substring to find.
 * @len: The maximum number of characters to search.
 *
 * Returns: A pointer to the first occurrence of @little in @big,
 *			or NULL if not found within @len characters.
 *
 * Notes:
 * - If @little is an empty string, returns @big.
 * - Stops searching when @len is reached, even if @little is not found.
 * - Not suitable for binary data; works only with null-terminated strings.
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && i + j < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
