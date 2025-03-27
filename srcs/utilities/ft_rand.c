/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:13:54 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 13:55:31 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_rand.c
 * @brief Random number generation using xorshift32 algorithm.
 *
 * This file contains the implementation of a simple random number generator
 * using the xorshift32 algorithm. The `ft_rand` function returns a random
 * integer within a specified range, [min, max].
 *
 * The algorithm uses a 32-bit state value that is initialized using the
 * system time, providing a simple but effective pseudo-random number generator.
 * 
 * @author nlouis
 * @date 2025/03/01
 * @ingroup utilities
 */
#include "libft.h"
 
 /**
 * @brief Performs a 32-bit xorshift operation to generate a pseudo-random number.
 *
 * This function implements the xorshift32 algorithm, a simple random number
 * generator that uses bitwise operations to produce pseudo-random numbers. 
 * It modifies the provided `state` and returns the resulting random number.
 *
 * @param state A pointer to the state value that is modified by the algorithm.
 *
 * @return The generated random number based on the current state.
 *
 * @see ft_rand
 * @ingroup utilities
 */
static unsigned int	xorshift32(unsigned int *state)
{
	*state ^= *state << 13;
	*state ^= *state >> 17;
	*state ^= *state << 5;
	return (*state);
}

/**
 * @brief Returns a random integer in the range [min, max] using xorshift32.
 *
 * This function uses the xorshift32 algorithm to generate a random number
 * between the specified minimum and maximum values, inclusive. The state is
 * initialized once using the system time and is then used to produce random
 * values.
 *
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (inclusive).
 *
 * @return A random integer between min and max, inclusive.
 *
 * @see xorshift32
 * @ingroup utilities
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
