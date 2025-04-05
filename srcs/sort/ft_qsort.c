/**
 * @file ft_qsort.c
 * @author Toonsa
 * @date 2025/04/05
 * @brief Generic quicksort implementation with fallback to insertion sort.
 *
 * @details
 * This file provides a general-purpose sorting utility based on the
 * quicksort algorithm. It includes a threshold-based fallback to
 * insertion sort for small segments and provides standard comparator
 * functions for integers and doubles.
 *
 * @ingroup sorting_utils
 */

 #include "libft.h"

 /**
  * @brief Comparison function for two doubles.
  *
  * @details
  * Compares the two doubles pointed to by @p a and @p b and returns
  * a standard comparator result.
  *
  * @param a Pointer to the first double.
  * @param b Pointer to the second double.
  * @return Negative if `a < b`, 0 if equal, positive if `a > b`.
  *
  * @see ft_qsort
  * @ingroup sorting_utils
  */
 int	double_cmp(const void *a, const void *b)
 {
	 double	da = *(const double *)a;
	 double	db = *(const double *)b;
 
	 return ((da > db) - (da < db));
 }
 
 /**
  * @brief Comparison function for two integers.
  *
  * @details
  * Compares the two integers pointed to by @p a and @p b and returns
  * a standard comparator result.
  *
  * @param a Pointer to the first integer.
  * @param b Pointer to the second integer.
  * @return Negative if `a < b`, 0 if equal, positive if `a > b`.
  *
  * @see ft_qsort
  * @ingroup sorting_utils
  */
 int	int_cmp(const void *a, const void *b)
 {
	 int	int_a = *(const int *)a;
	 int	int_b = *(const int *)b;
 
	 return ((int_a > int_b) - (int_a < int_b));
 }
 
 /**
  * @brief Returns a pointer to the i-th element in a base array.
  *
  * @param base Base pointer to the array.
  * @param i Index of the desired element.
  * @param size Size (in bytes) of each element.
  * @return Pointer to the i-th element.
  */
 static void	*get_elem(void *base, size_t i, size_t size)
 {
	 return ((char *)base + (i * size));
 }
 
 /**
  * @brief Sorts a subarray using insertion sort.
  *
  * @details
  * This function is used by quicksort for short segments. It sorts the
  * subarray from @p start to @p end in-place.
  *
  * @param base Base pointer to the array.
  * @param start Starting index of the subarray.
  * @param end Ending index of the subarray.
  * @param size Size (in bytes) of each element.
  * @param cmp Comparator function.
  */
 static void	insertion_sort(void *base, size_t start, size_t end,
				 size_t size, int (*cmp)(const void *, const void *))
 {
	 size_t			i;
	 ssize_t			j;
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
  * @brief Chooses a pivot using the median-of-three rule.
  *
  * @details
  * Selects the pivot as the median of the first, middle, and last elements
  * and swaps it into the @p end position.
  *
  * @param base Base pointer to the array.
  * @param start Start index.
  * @param end End index.
  * @param size Size (in bytes) of each element.
  * @param cmp Comparator function.
  * @return Index of the pivot (which will be at @p end).
  */
 static size_t	median_of_three(void *base, size_t start, size_t end,
					 size_t size, int (*cmp)(const void *, const void *))
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
  * @brief Partitions the array using Lomuto scheme.
  *
  * @details
  * Rearranges the array so that elements less than the pivot come before,
  * and those greater come after. Pivot is chosen with median-of-three.
  *
  * @param base Base pointer to the array.
  * @param start Start index.
  * @param end End index (pivot location).
  * @param size Size of each element in bytes.
  * @param cmp Comparator function.
  * @return Final pivot index after partitioning.
  */
 static size_t	partition(void *base, size_t start, size_t end, size_t size,
					 int (*cmp)(const void *, const void *))
 {
	 size_t	pivot_idx;
	 void	*pivot;
	 size_t	i;
	 size_t	j;
 
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
  * @brief Recursive quicksort with insertion sort fallback and tail-call optimization.
  *
  * @details
  * Sorts elements between @p start and @p end using quicksort. If the range
  * is below `QSORT_THRESHOLD`, switches to insertion sort.
  *
  * @param base Pointer to base of the array.
  * @param start Start index.
  * @param end End index.
  * @param size Element size in bytes.
  * @param cmp Comparator function.
  */
 static void	quicksort(void *base, size_t start, size_t end, size_t size,
						 int (*cmp)(const void *, const void *))
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
  * @brief Sorts an array using quicksort and insertion sort fallback.
  *
  * @details
  * Sorts an array of any type using a generic quicksort implementation.
  * Falls back to insertion sort for small subarrays.
  *
  * @param base Pointer to the first element of the array.
  * @param nmemb Number of elements in the array.
  * @param size Size in bytes of each element.
  * @param cmp Comparison function returning:
  *        - Negative if a < b
  *        - 0 if a == b
  *        - Positive if a > b
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
 