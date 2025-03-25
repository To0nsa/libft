/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:45:28 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:27:28 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strjoin()
 * Allocates and returns a new string, result of the concatenation of s1 and s2.
 *
 * @s1: The first input string. If NULL, it's treated as an empty string.
 * @s2: The second input string. If NULL, it's treated as an empty string.
 *
 * Returns: A newly allocated string containing s1 followed by s2,
 *          or NULL if allocation fails.
 *
 * Notes:
 * - Handles NULL inputs gracefully by treating them as empty strings.
 * - The resulting string is null-terminated.
 * - The caller is responsible for freeing the returned string.
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	new_str = (char *)malloc((total_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}

/**
 * ft_strjoin_and_free()
 * Concatenates two strings into a new one and frees the originals if requested.
 *
 * @s1: The first input string. If NULL, it's treated as an empty string.
 * @s2: The second input string. If NULL, it's treated as an empty string.
 * @free_s1: If non-zero, frees s1 after joining.
 * @free_s2: If non-zero, frees s2 after joining.
 *
 * Returns: A newly allocated string containing s1 followed by s2,
 *          or NULL if allocation fails.
 *
 * Notes:
 * - Useful for efficient string construction while managing memory.
 * - The resulting string is null-terminated.
 * - Caller is responsible for freeing the returned string.
 * - s1 and/or s2 will be freed depending on the flags.
 */
char	*ft_strjoin_and_free(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*new_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (new_str);
}
