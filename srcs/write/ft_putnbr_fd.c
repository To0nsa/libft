/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:42:46 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 10:02:10 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putnbr_fd()
 * Writes an integer to the given file descriptor.
 *
 * @n: The integer to write.
 * @fd: The file descriptor to write to.
 *
 * Returns: Nothing (void).
 *
 * Notes:
 * - Handles negative numbers, including the edge case of INT_MIN.
 * - Uses recursion to print digits in correct order.
 * - Converts digits to characters before writing.
 * - INT_MIN is handled separately to avoid overflow on negation.
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
