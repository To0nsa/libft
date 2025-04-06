/**
 * @file ft_sorting.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief Sorting utility functions and comparators.
 *
 * @details
 * This header defines general-purpose sorting functions and comparators
 * including a flexible `ft_qsort` implementation and integer/double
 * comparison helpers.
 *
 * @ingroup sorting_utils
 */

#ifndef FT_SORTING_H
#define FT_SORTING_H

/**
 * @defgroup sorting_utils Sorting Utilities
 * @brief General-purpose sorting utilities including a custom quicksort.
 *
 * @details
 * This group contains functions related to sorting arrays using a generic
 * implementation of the quicksort algorithm. It also includes basic comparator
 * functions for integers and doubles that can be passed to `ft_qsort`.
 *
 * @{
 */

#define QSORT_THRESHOLD 10 /**< Threshold to switch sort strategy */

void ft_qsort(void* base, size_t nmemb, size_t size,
              int (*cmp)(const void*, const void*));
int  double_cmp(const void* a, const void* b);
int  int_cmp(const void* a, const void* b);

/** @} */ // end of sorting_utils group

#endif
