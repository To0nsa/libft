/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:17:51 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:48:39 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putendl_fd.c
 * @brief File output function to write a string followed by a newline to a
 * file descriptor.
 *
 * This file contains the implementation of `ft_putendl_fd`, which writes
 * a string followed by a newline character to a specified file descriptor.
 *
 * @author nlouis
 * @date 2025/10/20
 * @ingroup file_output
 */
#include "libft.h"

/**
 * @brief Writes a string followed by a newline to a file descriptor.
 *
 * This function writes the string `s` followed by a newline character `\n`
 * to the file specified by the file descriptor `fd`. It is typically used
 * for outputting a string with a line break to a file or console.
 *
 * @param s The string to write.
 * @param fd The file descriptor to which the string and newline will be written.
 *
 * @ingroup file_output
 */
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
