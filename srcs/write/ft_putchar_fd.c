/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:41:53 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 10:01:28 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putchar_fd()
 * Writes a character to the given file descriptor.
 *
 * @c: The character to write.
 * @fd: The file descriptor to write to.
 *
 * Returns: Nothing (void).
 *
 * Notes:
 * - Typically used to write to standard output (fd = 1),
 *   or standard error (fd = 2).
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
