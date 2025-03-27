/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:00:55 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 12:08:05 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_qsort.c
 * @brief Implementation of a generic quicksort with median-of-three pivoting.
 *
 * This file contains the implementation of `ft_qsort`, which sorts any
 * array using the quicksort algorithm. It includes optimizations like
 * insertion sort for small partitions and median-of-three pivot selection.
 *
 * @author nlouis
 * @date 2024/12/13
 * @ingroup sorting_utils
 */
#include "libft.h"

/**
 * @brief Gets the pointer to the i-th element of an array.
 *
 * @param base Base pointer of the array.
 * @param i Index of the element.
 * @param size Size in bytes of each element.
 * @return Pointer to the i-th element.
 */
static void	*get_elem(void *base, size_t i, size_t size)
{
	return ((char *)base + (i * size));
}

/**
 * @brief Sorts a subarray using insertion sort.
 *
 * Used by `quicksort` when the subarray size is below the threshold.
 *
 * @param base Base pointer of the array.
 * @param start Start index of the subarray.
 * @param end End index of the subarray.
 * @param size Size of each element.
 * @param cmp Comparison function.
 */
static void	insertion_sort(void *base, size_t start, size_t end,
				size_t size, int (*cmp)(const void*, const void*))
{
	size_t			i;	// current index
	ssize_t			j;	// comparaison index
	unsigned char	temp[256];

	i = start + 1;
	while (i <= end)
	{
		ft_memcpy(temp, get_elem(base, i, size), size);
		j = i - 1;
		while (j >= (ssize_t)start && cmp(get_elem(base, j, size), temp) > 0)
		{
			ft_memcpy(get_elem(base, j + 1, size), get_elem(base, j, size), size);
			j--;
		}
		ft_memcpy(get_elem(base, j + 1, size), temp, size);
		i++;
	}
}

/**
 * @brief Selects a pivot using the median-of-three method.
 *
 * Swaps the median of the first, middle, and last element to the end.
 *
 * @param base Base pointer of the array.
 * @param start Start index of the subarray.
 * @param end End index of the subarray.
 * @param size Size of each element.
 * @param cmp Comparison function.
 * @return Index of the pivot element (moved to the end).
 */
static size_t	median_of_three(void *base, size_t start, size_t end,
					size_t size, int (*cmp)(const void*, const void*))
{
	size_t	mid;

	mid = start + (end - start) / 2;
	if (cmp(get_elem(base, start, size), get_elem(base, mid, size)) > 0)
		ft_swap(get_elem(base, start, size), get_elem(base, mid, size), size);
	if (cmp(get_elem(base, start, size), get_elem(base, end, size)) > 0)
		ft_swap(get_elem(base, start, size), get_elem(base, end, size), size);
	if (cmp(get_elem(base, mid, size), get_elem(base, end, size)) > 0)
		ft_swap(get_elem(base, mid, size), get_elem(base, end, size), size);
	ft_swap(get_elem(base, mid, size), get_elem(base, end, size), size);
	return (end);
}

/**
 * @brief Partitions the array using Lomuto partition scheme.
 *
 * Moves elements less than the pivot to the left and greater ones to the
 * right.
 *
 * @param base Base pointer of the array.
 * @param start Start index of the subarray.
 * @param end End index of the subarray (pivot).
 * @param size Size of each element.
 * @param cmp Comparison function.
 * @return Final pivot index.
 */
static size_t	partition(void *base, size_t start, size_t end, size_t size,
					int (*cmp)(const void*, const void*))
{
	size_t	pivot_idx;
	void	*pivot;
	size_t	i;	// partition boundary
	size_t	j;	// traversal index

	pivot_idx = median_of_three(base, start, end, size, cmp);
	pivot = get_elem(base, pivot_idx, size);
	i = start;
	j = start;
	while (j < end)
	{
		if (cmp(get_elem(base, j, size), pivot) < 0)
		{
			ft_swap(get_elem(base, i, size), get_elem(base, j, size), size);
			i++;
		}
		j++;
	}
	ft_swap(get_elem(base, i, size), get_elem(base, end, size), size);
	return (i);
}

/**
 * @brief Recursive quicksort implementation with tail call optimization.
 *
 * Recursively sorts the smaller partition first to avoid stack overflow.
 * Uses insertion sort for small subarrays.
 *
 * @param base Base pointer of the array.
 * @param start Start index.
 * @param end End index.
 * @param size Size of each element.
 * @param cmp Comparison function.
 */
static void	quicksort(void *base, size_t start, size_t end, size_t size,
						int (*cmp)(const void*, const void*))
{
	size_t	pivot;

	while (start < end)
	{
		if ((end - start + 1) < QSORT_THRESHOLD)
		{
			insertion_sort(base, start, end, size, cmp);
			break ;
		}
		pivot = partition(base, start, end, size, cmp);
		if ((pivot - start) < (end - pivot))
		{
			if (pivot > 0)
				quicksort(base, start, pivot - 1, size, cmp);
			start = pivot + 1;
		}
		else
		{
			quicksort(base, pivot + 1, end, size, cmp);
			if (pivot == 0)
				break ;
			end = pivot - 1;
		}
	}
}

/**
 * @brief Sorts a generic array using quicksort with insertion fallback.
 *
 * This function sorts an array of any data type using the quicksort
 * algorithm. For small subarrays, insertion sort is used instead for better
 * performance.
 *
 * @param base Pointer to the first element of the array.
 * @param nmemb Number of elements in the array.
 * @param size Size (in bytes) of each element.
 * @param cmp Comparison function, must return:
 *            - Negative if first < second
 *            - Zero if first == second
 *            - Positive if first > second
 *
 * @see int_cmp
 * @see double_cmp
 * @ingroup sorting_utils
 */
void	ft_qsort(void *base, size_t nmemb, size_t size,
			int (*cmp)(const void *, const void *))
{
	if (!base || nmemb <= 1 || !cmp)
		return ;
	quicksort(base, 0, nmemb - 1, size, cmp);
}

