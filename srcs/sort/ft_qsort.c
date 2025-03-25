/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:00:55 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 10:55:33 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Helper to access element at index i in the array.
 */
static void	*get_elem(void *base, size_t i, size_t size)
{
	return ((char *)base + (i * size));
}

/*
 * Insertion sort for small partitions.
 * Efficient for small sub-arrays.
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

/*
 * Median-of-three pivot selection for improved performance.
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

/*
 * Partition around pivot.
 * Returns pivot index.
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

/*
 * QuickSort main logic (optimized tail recursion, insertion sort threshold).
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

/*
 * ft_qsort()
 * Generic quicksort implementation.
 *
 * @base: Pointer to the array to sort.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 * @cmp: Comparison function (returns <0, 0, or >0).
 *
 * Notes:
 * - Uses median-of-three pivot selection for optimal pivots.
 * - Switches to insertion sort for small partitions (QSORT_THRESHOLD).
 * - Optimizes recursion to avoid stack overflows.
 */
void	ft_qsort(void *base, size_t nmemb, size_t size,
			int (*cmp)(const void *, const void *))
{
	if (!base || nmemb <= 1 || !cmp)
		return ;
	quicksort(base, 0, nmemb - 1, size, cmp);
}

