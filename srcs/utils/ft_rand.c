/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:13:54 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 09:59:54 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * xorshift32()
 * Generates a pseudo-random 32-bit number using the Xorshift algorithm.
 *
 * @state: A pointer to the internal state of the generator.
 *
 * Returns: A new pseudo-random number, and updates the internal state.
 *
 * Notes:
 * - Xorshift is fast and suitable for non-cryptographic randomness.
 * - Should be seeded with a non-zero value for good randomness.
 */
static unsigned int	xorshift32(unsigned int *state)
{
	*state ^= *state << 13;
	*state ^= *state >> 17;
	*state ^= *state << 5;
	return (*state);
}

/**
 * ft_rand()
 * Returns a pseudo-random integer within the range [min, max].
 *
 * @min: The minimum value (inclusive).
 * @max: The maximum value (inclusive).
 *
 * Returns: A pseudo-random number between min and max.
 *
 * Notes:
 * - Initializes the internal state using gettimeofday() if not already done.
 * - Uses xorshift32() as the random number generator.
 * - Thread-unsafe; use caution in multithreaded contexts.
 * - Behavior is undefined if max < min.
 */
int	ft_rand(int min, int max)
{
	static unsigned int	state;
	struct timeval		tv;

	if (state == 0)
	{
		gettimeofday(&tv, NULL);
		state = (unsigned int)(tv.tv_sec ^ tv.tv_usec);
	}
	return (min + (xorshift32(&state) % (max - min + 1)));
}
