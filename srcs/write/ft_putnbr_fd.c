/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:42:46 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:48:35 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_fd.c
 * @brief File output function to write an integer to a file descriptor.
 *
 * This file contains the implementation of `ft_putnbr_fd`, which writes
 * an integer to the specified file descriptor. It handles negative values
 * and the special case for the minimum integer value (`-2147483648`).
 *
 * @author nlouis
 * @date 2024/10/21
 * @ingroup file_output
 */
#include "libft.h"

/**
 * @brief Writes an integer to a file descriptor.
 *
 * This function writes the integer `n` to the file specified by the file
 * descriptor `fd`. If the integer is negative, it first writes the negative
 * sign. For values greater than 9, it recursively writes the digits of the
 * integer from left to right.
 *
 * The special case of the minimum integer value (`-2147483648`) is handled
 * separately because it cannot be negated without causing overflow.
 *
 * @param n The integer to write.
 * @param fd The file descriptor to which the integer will be written.
 *
 * @ingroup file_output
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
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
