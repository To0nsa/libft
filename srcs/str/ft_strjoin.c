/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:45:28 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:06:31 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strjoin.c
 * @brief Concatenates two strings into a new one.
 *
 * This file provides the implementation of functions to join two strings
 * (`ft_strjoin`) and a variant that optionally frees the input strings
 * after concatenation (`ft_strjoin_and_free`).
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup string_utils
 */
#include "libft.h"

/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * Allocates a new string containing the contents of `s1` followed by `s2`.
 * If either string is NULL, it is treated as an empty string.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A new string containing the concatenation of `s1` and `s2`,
 *         or NULL if memory allocation fails.
 *
 * @note The caller is responsible for freeing the returned string.
 *
 * @see ft_strlen
 * @see ft_strlcpy
 * @ingroup string_utils
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
 * @brief Concatenates two strings and optionally frees the originals.
 *
 * This function joins two strings into a new one. Depending on the values of
 * `free_s1` and `free_s2`, it can free the memory of `s1` and/or `s2` after
 * use.
 *
 * @param s1 First string to join.
 * @param s2 Second string to join.
 * @param free_s1 If non-zero, `s1` is freed after concatenation.
 * @param free_s2 If non-zero, `s2` is freed after concatenation.
 *
 * @return A new string containing the concatenation of `s1` and `s2`,
 *         or NULL if allocation fails.
 *
 * @note If `s1` or `s2` is NULL, it is replaced with an empty string.
 *
 * @see ft_strdup
 * @see ft_strlen
 * @see ft_strlcpy
 * @ingroup string_utils
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
