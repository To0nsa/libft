/**
 * @file ft_output.c
 * @author ...
 * @date 2025-04-05
 * @brief File descriptor-based output functions.
 *
 * @details
 * Implements low-level output helpers that write characters, strings,
 * and integers to a specific file descriptor. Includes error handling
 * for partial writes and system interruptions.
 *
 * @ingroup file_output
 */

#include "libft.h"

/**
 * @brief Writes a single character to a file descriptor.
 *
 * @details
 * This function writes the character @p c to the file specified by
 * @p fd. It is primarily used for outputting a single character to
 * a file or standard output.
 *
 * @param c The character to write.
 * @param fd The file descriptor to which the character will be written.
 *
 * @ingroup file_output
 */
void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/**
 * @brief Writes a string followed by a newline to a file descriptor.
 *
 * @details
 * This function writes the string @p s followed by a newline character
 * (`\n`) to the file descriptor @p fd. Commonly used to print lines of text.
 *
 * @param s The string to write.
 * @param fd The file descriptor to which the string and newline will be written.
 *
 * @ingroup file_output
 */
void ft_putendl_fd(char* s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/**
 * @brief Writes an integer to a file descriptor.
 *
 * @details
 * Outputs the integer @p n as a string of digits to the given @p fd.
 * Handles negative numbers and the special case of `INT_MIN`.
 *
 * @param n The integer to write.
 * @param fd The file descriptor to which the integer will be written.
 *
 * @ingroup file_output
 */
void ft_putnbr_fd(int n, int fd)
{
	char digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

/**
 * @brief Writes a string to a file descriptor.
 *
 * @details
 * This function writes the null-terminated string @p str to the file
 * descriptor @p fd. It handles system interruptions (e.g., `EINTR`) and
 * retries as needed until the full string is written or an unrecoverable
 * error occurs.
 *
 * @param str The string to write.
 * @param fd The file descriptor to which the string will be written.
 *
 * @return The total number of bytes written, or -1 on error.
 *
 * @ingroup file_output
 */
int ft_putstr_fd(char* str, int fd)
{
	int bytes_written;
	int total_written;
	int len;

	if (str == NULL)
		return (-1);
	total_written = 0;
	len           = ft_strlen(str);
	while (total_written < len)
	{
		bytes_written = write(fd, str + total_written, len - total_written);
		if (bytes_written == -1)
		{
			if (errno == EINTR)
				continue;
			return (-1);
		}
		total_written += bytes_written;
	}
	return (total_written);
}
