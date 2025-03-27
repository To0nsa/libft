/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:41:53 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:48:44 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putchar_fd.c
 * @brief File output function to write a single character to a file descriptor.
 *
 * This file contains the implementation of `ft_putchar_fd`, which writes
 * a single character to a specified file descriptor.
 *
 * @author nlouis
 * @date 2025/10/21
 * @ingroup file_output
 */
#include "libft.h"

/**
 * @brief Writes a single character to a file descriptor.
 *
 * This function writes the character `c` to the file specified by the
 * file descriptor `fd`. It is primarily used for outputting a single
 * character to a file or console.
 *
 * @param c The character to write.
 * @param fd The file descriptor to which the character will be written.
 *
 * @ingroup file_output
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
