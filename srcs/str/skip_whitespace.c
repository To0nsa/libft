/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:13:08 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 22:51:50 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	skip_whitespace_index(const char *input, int *i)
{
	while (ft_isspace(input[*i]))
		(*i)++;
}

char	*skip_whitespace_ptr(const char *s)
{
	while (ft_isspace(*s))
		s++;
	return ((char *)s);
}
