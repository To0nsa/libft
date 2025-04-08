/**
 * @file ft_utils.c
 * @author Toonsa
 * @date 2025-04-05
 * @brief General-purpose utility functions.
 *
 * @details
 * This file contains reusable helpers such as `ft_swap` for memory-safe
 * value swapping, and `ft_rand` for pseudo-random integer generation
 * using the xorshift32 algorithm.
 *
 * @ingroup utilities
 */

#include "libft.h"

/**
 * @brief Swaps the contents of two memory blocks.
 *
 * @details
 * This function swaps the contents of two memory locations @p a and @p b of
 * the specified @p size. The swap is performed using a temporary buffer to
 * prevent data loss. It is essential to ensure that both pointers are
 * non-NULL, and that the size is greater than zero for the function to work.
 *
 * The function internally uses `ft_memcpy` to copy the contents between
 * the two locations. After the swap, the temporary buffer is freed to avoid
 * memory leaks.
 *
 * @param a A pointer to the first memory block.
 * @param b A pointer to the second memory block.
 * @param size The size of the memory blocks being swapped.
 *
 * @note If either @p a, @p b, or @p size is invalid (NULL or zero), the
 * function does nothing.
 *
 * @see ft_memcpy
 * @ingroup utilities
 */
void ft_swap(void* a, void* b, size_t size)
{
	void* tmp;

	if (!a || !b || size == 0)
		return;
	tmp = malloc(size);
	if (!tmp)
		return;
	ft_memcpy(tmp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, tmp, size);
	free(tmp);
}

/**
 * @brief Performs a 32-bit xorshift operation to generate a pseudo-random
 * number.
 *
 * @details
 * This function implements the xorshift32 algorithm, a simple random number
 * generator that uses bitwise operations to produce pseudo-random numbers.
 * It modifies the provided @p state and returns the resulting random number.
 *
 * @param state A pointer to the state value that is modified by the algorithm.
 *
 * @return The generated random number based on the current state.
 *
 * @see ft_rand
 * @ingroup utilities
 */
static unsigned int xorshift32(unsigned int* state)
{
	*state ^= *state << 13;
	*state ^= *state >> 17;
	*state ^= *state << 5;
	return (*state);
}

/**
 * @brief Returns a random integer in the range [min, max] using xorshift32.
 *
 * @details
 * This function uses the xorshift32 algorithm to generate a random number
 * between the specified minimum and maximum values, inclusive. The state is
 * initialized once using the system time and is then used to produce random
 * values.
 *
 * @param min The minimum value of the range (inclusive).
 * @param max The maximum value of the range (inclusive).
 *
 * @return A random integer between @p min and @p max, inclusive.
 *
 * @see xorshift32
 * @ingroup utilities
 */
int ft_rand(int min, int max)
{
	static unsigned int state;
	struct timeval      tv;

	if (state == 0)
	{
		gettimeofday(&tv, NULL);
		state = (unsigned int) (tv.tv_sec ^ tv.tv_usec);
	}
	return (min + (xorshift32(&state) % (max - min + 1)));
}
