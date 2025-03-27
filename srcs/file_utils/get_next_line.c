/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:53:52 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:37:22 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief Implementation of the get_next_line function.
 *
 * This file provides an implementation of the `get_next_line` function,
 * which reads a line (terminated by `\n` or EOF) from a file descriptor.
 *
 * It supports multiple file descriptors in parallel by using a static array
 * indexed by the file descriptor number. Each call returns one full line,
 * including the newline character, if present.
 *
 * @note Requires a properly defined BUFFER_SIZE macro and MAX_FD for
 *       maximum number of file descriptors.
 * 
 * @author nlouis
 * @date 2025/02/25
 * @ingroup file_utils
 */
#include "libft.h"

/**
 * @brief Reads from a file descriptor and appends to the remainder buffer.
 *
 * Allocates a buffer and reads into it until a newline is found or EOF
 * is reached. The content is appended to `*remainder`. Handles memory
 * reallocation and appends data using `ft_strjoin`.
 *
 * @param fd The file descriptor to read from.
 * @param remainder Pointer to the remainder buffer (modified in place).
 * 
 * @return The number of bytes read, or -1 on error.
 * 
 * @see ft_strdup
 * @see ft_strchr
 * @see ft_strjoin
 * @ingroup file_utils
 */
static ssize_t	read_and_store(int fd, char **remainder)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*new_remainder;

	if (*remainder == NULL)
		*remainder = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while ((ft_strchr(*remainder, '\n') == NULL) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), -1);
		buffer[bytes_read] = '\0';
		new_remainder = ft_strjoin(*remainder, buffer);
		if (!new_remainder)
			return (free(buffer), -1);
		free(*remainder);
		*remainder = new_remainder;
	}
	free(buffer);
	return (bytes_read);
}

/**
 * @brief Extracts the next line from the remainder buffer.
 *
 * Finds the first newline or end of string and returns a new string
 * containing that line. Includes the newline if present.
 *
 * @param remainder The current buffer containing file content.
 * 
 * @return A new string containing the extracted line, or NULL on failure.
 * 
 * @see ft_substr
 * @ingroup file_utils
 */
static char	*extract_line(char *remainder)
{
	size_t	line_len;
	char	*line;

	line_len = 0;
	if (!remainder || !remainder[0])
		return (NULL);
	while (remainder[line_len] && remainder[line_len] != '\n')
		line_len++;
	if (remainder[line_len] == '\n')
		line_len++;
	line = ft_substr(remainder, 0, line_len);
	if (!line)
		return (NULL);
	return (line);
}

/**
 * @brief Updates the remainder buffer after a line has been extracted.
 *
 * Removes the line that was already returned from the buffer and retains
 * only the remaining data after the newline character.
 *
 * @param remainder The buffer to update (will be freed and replaced).
 * 
 * @return The updated remainder, or NULL if nothing is left.
 * 
 * @see ft_strlen
 * @see ft_substr
 * @ingroup file_utils
 */
static char	*update_remainder(char *remainder)
{
	char	*new_remainder;
	size_t	line_len;
	size_t	remainder_len;

	if (!remainder)
		return (NULL);
	line_len = 0;
	while (remainder[line_len] && remainder[line_len] != '\n')
		line_len++;
	if (remainder[line_len] == '\n')
		line_len++;
	if (remainder[line_len] == '\0')
	{
		free(remainder);
		return (NULL);
	}
	remainder_len = ft_strlen(remainder);
	new_remainder = ft_substr(remainder, line_len, remainder_len - line_len);
	free(remainder);
	if (!new_remainder)
		return (NULL);
	return (new_remainder);
}

/**
 * @brief Reads the next line from a file descriptor.
 *
 * Reads data from the given file descriptor and returns the next full line.
 * If no data is left, or an error occurs, returns NULL.
 *
 * Internally uses a static array to maintain state across multiple calls
 * and supports multiple file descriptors.
 *
 * @param fd The file descriptor to read from.
 * @return A string containing the next line, or NULL on EOF or error.
 *
 * @note The caller must free the returned string.
 * @note The function relies on the macros BUFFER_SIZE and MAX_FD being set.
 * 
 * @see ft_strdup
 * @see read_and_store
 * @see extract_line
 * @see update_remainder
 * @ingroup file_utils
 */
char	*get_next_line(int fd)
{
	static char	*remainder[MAX_FD];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	if (!remainder[fd])
	{
		remainder[fd] = ft_strdup("");
		if (!remainder[fd])
			return (NULL);
	}
	bytes_read = read_and_store(fd, &remainder[fd]);
	if (bytes_read == -1 || (bytes_read == 0 && remainder[fd][0] == '\0'))
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	line = extract_line(remainder[fd]);
	if (!line)
		return (NULL);
	remainder[fd] = update_remainder(remainder[fd]);
	return (line);
}
