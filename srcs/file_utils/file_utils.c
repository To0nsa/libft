/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 23:36:14 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:37:19 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_file_utils.c
 * @brief Utility functions for safe file operations.
 *
 * This file provides wrapper functions for standard file operations such as
 * `open`, `read`, and `close`, with built-in error checking and messaging.
 * These are intended to improve robustness and debugging convenience.
 *
 * @author nlouis
 * @date 2025/02/18
 * @ingroup file_utils
 */
#include "libft.h"

/**
 * @brief Safely opens a file with the given flags.
 *
 * This function attempts to open a file using the specified `flags`. If the
 * filename is NULL or the operation fails, an error message is printed to
 * stderr.
 *
 * @param filename The path to the file to be opened.
 * @param flags    The file access mode flags (e.g., O_RDONLY, O_WRONLY, etc.).
 *
 * @return The file descriptor on success, or -1 on failure.
 * @ingroup file_utils
 */
int	ft_open_file(const char *filename, int flags)
{
	int	fd;

	if (!filename)
	{
		write(2, "Error: Invalid filename\n", 24);
		return (-1);
	}
	fd = open(filename, flags);
	if (fd < 0)
		perror("Error opening file");
	return (fd);
}

/**
 * @brief Safely reads data from a file descriptor.
 *
 * This function reads up to `size` bytes from the given file descriptor into
 * the provided `buffer`. It performs basic validation and reports read errors.
 *
 * @param fd     The file descriptor to read from.
 * @param buffer A pointer to the buffer where data will be stored.
 * @param size   The number of bytes to read.
 *
 * @return The number of bytes read, or -1 on failure.
 * @ingroup file_utils
 */
ssize_t	ft_read_file(int fd, void *buffer, size_t size)
{
	ssize_t	bytes_read;

	if (fd < 0 || !buffer)
	{
		write(2, "Error: Invalid file descriptor or buffer\n", 41);
		return (-1);
	}
	bytes_read = read(fd, buffer, size);
	if (bytes_read < 0)
		perror("Error reading file");
	return (bytes_read);
}

/**
 * @brief Safely closes a file descriptor.
 *
 * This function closes the file descriptor if it is valid. If the operation
 * fails, an error message is printed.
 *
 * @param fd The file descriptor to be closed.
 *
 * @return 0 on success, or -1 on failure.
 * @ingroup file_utils
 */
int	ft_safe_close(int fd)
{
	if (fd >= 0)
	{
		if (close(fd) < 0)
		{
			perror("Error closing file");
			return (-1);
		}
	}
	return (0);
}
