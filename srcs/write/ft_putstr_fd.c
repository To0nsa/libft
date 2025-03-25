/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:43:12 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 10:02:38 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putstr_fd()
 * Writes a string to the given file descriptor with robust error handling.
 *
 * @str: The null-terminated string to write.
 * @fd: The file descriptor to write to.
 *
 * Returns: The total number of bytes written on success,
 *          or -1 on error.
 *
 * Notes:
 * - Handles partial writes and interruptions (EINTR).
 * - Returns -1 immediately if @str is NULL or a fatal write error occurs.
 * - Unlike the standard libft version, this implementation is more robust.
 */
int	ft_putstr_fd(char *str, int fd)
{
	int	bytes_written;
	int	total_written;
	int	len;

	if (str == NULL)
		return (-1);
	total_written = 0;
	len = ft_strlen(str);
	while (total_written < len)
	{
		bytes_written = write(fd, str + total_written, len - total_written);
		if (bytes_written == -1)
		{
			if (errno == EINTR)
				continue ;
			return (-1);
		}
		total_written += bytes_written;
	}
	return (total_written);
}
