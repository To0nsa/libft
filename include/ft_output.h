/**
 * @file ft_output.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief File descriptor-based output functions.
 *
 * @details
 * This header provides functions for writing characters, strings,
 * and numbers to a specified file descriptor. These are useful for
 * low-level formatted output in logging, CLI tools, or system-level utilities.
 *
 * @ingroup file_output
 */

#ifndef FT_OUTPUT_H
#define FT_OUTPUT_H

/**
 * @defgroup file_output File Descriptor Output
 * @brief Output utilities for writing to file descriptors.
 *
 * @details
 * Functions that output characters, strings, and integers to
 * a given file descriptor. These are useful in systems without
 * standard output libraries.
 *
 * This group includes:
 * - @ref ft_putchar_fd
 * - @ref ft_putstr_fd
 * - @ref ft_putendl_fd
 * - @ref ft_putnbr_fd
 * @{
 */

void ft_putchar_fd(char c, int fd);
int  ft_putstr_fd(char* str, int fd);
void ft_putendl_fd(char* s, int fd);
void ft_putnbr_fd(int n, int fd);

/** @} */ // end of file_output group

#endif
