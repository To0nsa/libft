/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:17:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 10:01:49 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putendl_fd()
 * Writes a string followed by a newline to the given file descriptor.
 *
 * @s: The string to write.
 * @fd: The file descriptor to write to.
 *
 * Returns: Nothing (void).
 *
 * Notes:
 * - Writes the string using its full length (ft_strlen).
 * - Appends a newline character after the string.
 * - If @s is NULL, the behavior is undefined (no null check).
 */
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
