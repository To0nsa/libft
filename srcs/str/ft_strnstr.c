/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:47:53 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:14:39 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnstr.c
 * @brief Locates a substring in a string within a limited length.
 *
 * This file contains the implementation of `ft_strnstr`, a function that 
 * searches for the first occurrence of the substring `little` in the string 
 * `big`, but not beyond `len` characters.
 * 
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Searches for a substring in a string within a max length.
 *
 * This function searches for the first occurrence of the null-terminated
 * string `little` in the string `big`, where not more than `len` characters
 * are searched. Characters after a `\0` character are not searched.
 *
 * If `little` is an empty string, `big` is returned. If `little` occurs
 * nowhere in `big` within the first `len` characters, NULL is returned.
 *
 * @param big    The main string to be searched.
 * @param little The substring to search for.
 * @param len    The maximum number of characters to search in `big`.
 *
 * @return A pointer to the first occurrence of `little` in `big` within
 *         `len` characters, or NULL if not found.
 *
 * @ingroup string_utils
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
