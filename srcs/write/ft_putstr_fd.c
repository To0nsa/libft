/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:43:12 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:50:11 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr_fd.c
 * @brief File output function to write a string to a file descriptor.
 *
 * This file contains the implementation of `ft_putstr_fd`, which writes
 * a string to the specified file descriptor. It ensures that all the string
 * is written, even if interruptions happen (e.g., `EINTR`).
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup file_output
 */
#include "libft.h"

/**
 * @brief Writes a string to a file descriptor.
 *
 * This function writes the null-terminated string `str` to the file
 * specified by the file descriptor `fd`. It handles interruptions during
 * the write process (e.g., `EINTR`), ensuring that the entire string is written.
 * If the string is `NULL`, it returns `-1`. It returns the total number of
 * bytes written on success.
 *
 * @param str The string to write.
 * @param fd The file descriptor to which the string will be written.
 *
 * @return The total number of bytes written, or -1 on error.
 * 
 * @ingroup file_output
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
