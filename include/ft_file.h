/**
 * @file ft_file.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief File utility functions for simplified and safe file operations.
 *
 * @details
 * This header declares helper functions for interacting with files.
 * It includes wrappers around system calls like `open`, `read`, and `close`,
 * providing consistent error handling and improved safety.
 *
 * It also includes the `get_next_line` function for reading input line-by-line.
 *
 * @ingroup file_utils
 */

#ifndef FT_FILE_H
#define FT_FILE_H

/**
 * @defgroup file_utils File Utilities
 * @brief Helper functions for basic file operations.
 *
 * @details
 * These functions simplify and secure standard file operations,
 * including reading, opening, closing, and line-by-line parsing.
 *
 * This group includes:
 * - @ref ft_open_file
 * - @ref ft_read_file
 * - @ref ft_safe_close
 * - @ref get_next_line
 * @{
 */

/**
 * @brief Default buffer size for reading operations like `get_next_line`.
 */
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

/**
 * @brief Maximum number of file descriptors supported simultaneously.
 *
 * Used internally to manage static buffers indexed by file descriptors.
 */
#define MAX_FD 1024

/**
 * @brief Opens a file with the given flags.
 *
 * @param filename The path to the file.
 * @param flags Flags such as O_RDONLY, O_WRONLY, etc.
 * @return The file descriptor on success, or -1 on failure.
 */
int ft_open_file(const char* filename, int flags);

/**
 * @brief Reads a specified number of bytes from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @param buffer The buffer to store the read data.
 * @param size The number of bytes to read.
 * @return The number of bytes read, or -1 on error.
 */
ssize_t ft_read_file(int fd, void* buffer, size_t size);

/**
 * @brief Closes a file descriptor safely.
 *
 * @param fd The file descriptor to close.
 * @return 0 on success, or -1 on error.
 */
int ft_safe_close(int fd);

/**
 * @brief Reads a line from a file descriptor.
 *
 * This function returns a line terminated by a newline character `\n`,
 * or the end of file.
 *
 * @param fd The file descriptor to read from.
 * @return A newly allocated string containing the line, or NULL on failure.
 */
char* get_next_line(int fd);

/** @} */ // end of file_utils group

#endif
