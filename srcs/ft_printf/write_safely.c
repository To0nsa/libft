/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_safely.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:35:58 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:35 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file write_safely.c
 * @brief Safe write functions used by ft_printf.
 *
 * This file contains wrapper functions around the `write` system call
 * that ensure full string or character output, while also handling
 * interruptions (`EINTR`) and updating error and byte tracking through
 * a `t_pf` structure.
 *
 * These functions are used throughout `ft_printf` to safely accumulate
 * output data.
 *
 * @author nlouis
 * @date 2024/11/30
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Writes a string safely to a file descriptor.
 *
 * Writes the entire string `str` to the given file descriptor `fd`,
 * handling partial writes and system interruptions (`EINTR`). On error,
 * it sets `pf->write_error` to 1. On success, it increments `pf->total`
 * by the number of bytes written.
 *
 * @param fd The file descriptor to write to.
 * @param str The null-terminated string to write.
 * @param pf Pointer to a `t_pf` struct for tracking state.
 * 
 * @see ft_strlen
 * @ingroup ft_printf
 */
void	write_safely(int fd, char *str, t_pf *pf)
{
	ssize_t	bytes_written;
	size_t	total_written;
	size_t	len;

	if (str == NULL)
		return ;
	total_written = 0;
	len = ft_strlen(str);
	while (total_written < len)
	{
		bytes_written = write(fd, str + total_written, len - total_written);
		if (bytes_written == -1)
		{
			if (errno == EINTR)
				continue ;
			pf->write_error = 1;
			return ;
		}
		total_written += bytes_written;
	}
	pf->total += total_written;
}

/**
 * @brief Writes a fixed number of bytes from a string to a file descriptor.
 *
 * Similar to `write_safely`, but instead of a null-terminated string,
 * this function writes exactly `len` bytes. Handles partial writes and
 * sets `pf->write_error` on failure. Updates `pf->total` on success.
 *
 * @param fd The file descriptor to write to.
 * @param str The string containing data to write.
 * @param len Number of bytes to write from `str`.
 * @param pf Pointer to a `t_pf` struct for tracking state.
 * 
 * @ingroup ft_printf
 */
void	write_safely_len(int fd, char *str, size_t len, t_pf *pf)
{
	ssize_t	bytes_written;
	size_t	total_written;

	if (str == NULL)
		return ;
	total_written = 0;
	while (total_written < len)
	{
		bytes_written = write(fd, str + total_written, len - total_written);
		if (bytes_written == -1)
		{
			if (errno == EINTR)
				continue ;
			pf->write_error = 1;
			return ;
		}
		total_written += bytes_written;
	}
	pf->total += total_written;
}

/**
 * @brief Safely writes a single character to a file descriptor.
 *
 * Writes one character `c` to file descriptor `fd`. If interrupted by a
 * signal (`EINTR`), the write is retried. On other errors, sets
 * `pf->write_error`. On success, adds 1 to `pf->total`.
 *
 * @param fd The file descriptor to write to.
 * @param c The character to write.
 * @param pf Pointer to a `t_pf` struct for tracking state.
 * 
 * @ingroup ft_printf
 */
void	write_char_safely(int fd, char c, t_pf *pf)
{
	ssize_t	bytes_written;

	bytes_written = write(fd, &c, 1);
	if (bytes_written == -1)
	{
		if (errno == EINTR)
		{
			write_char_safely(fd, c, pf);
			return ;
		}
		pf->write_error = 1;
		return ;
	}
	pf->total += bytes_written;
}
