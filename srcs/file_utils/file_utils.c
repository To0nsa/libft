/**
 * @file ft_file_utils.c
 * @author Toonsa
 * @date 2025/02/18
 * @brief Utility functions for safe file operations.
 *
 * @details
 * This file provides wrapper functions for standard file operations such as
 * `open`, `read`, and `close`, with built-in error checking and messaging.
 * These functions are intended to provide safer and more debuggable
 * alternatives to standard system calls.
 *
 * @ingroup file_utils
 */

 #include "libft.h"

 /**
  * @brief Safely opens a file with the given flags.
  *
  * @details
  * If the provided filename is NULL or if `open` fails, this function reports
  * the error to `stderr` using `perror`.
  *
  * @param filename The path to the file to be opened.
  * @param flags    File access flags (e.g., O_RDONLY, O_WRONLY).
  *
  * @return The file descriptor on success, or -1 on failure.
  *
  * @note This function is useful for reducing boilerplate when opening files.
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
  * @details
  * This function validates the file descriptor and buffer before attempting
  * to read. On failure, it prints a message to `stderr`.
  *
  * @param fd     The file descriptor to read from.
  * @param buffer Pointer to the destination buffer.
  * @param size   Number of bytes to read.
  *
  * @return The number of bytes read on success, or -1 on error.
  *
  * @note This function helps avoid common misuse of `read()`.
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
  * @details
  * This function closes a valid file descriptor and reports any error using
  * `perror`.
  *
  * @param fd The file descriptor to close.
  *
  * @return 0 on success, or -1 if closing fails.
  *
  * @note This function should always be used to close file descriptors in a
  * safe and consistent manner.
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
 
