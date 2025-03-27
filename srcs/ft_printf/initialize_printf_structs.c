/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_printf_structs.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:05:48 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/26 11:38:08 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file initialize_printf_structs.c
 * @brief Initialization functions for ft_printf internal structures.
 *
 * This file provides helper functions to initialize the formatting
 * and state structures used by the custom `ft_printf` implementation.
 * These include setup for total printed characters, flags, width,
 * precision, and memory allocation for formatting context.
 *
 * @author nlouis
 * @date 2024/12/01
 * @ingroup ft_printf
 */
#include "libft.h"

/**
 * @brief Initializes the `t_pf` structure to default values.
 *
 * Sets the counters and error tracking fields to 0 to prepare for
 * a new `ft_printf` execution. This structure tracks total characters
 * written and whether any memory or write errors occurred.
 *
 * @param pf A pointer to the `t_pf` structure to initialize.
 * 
 * @ingroup ft_printf
 */
static void	initialize_pf(t_pf *pf)
{
	pf->total = 0;
	pf->write_error = 0;
	pf->malloc_error = 0;
}

/**
 * @brief Initializes the `t_fmt` structure for format specifications.
 *
 * Resets format-related fields to defaults:
 * - flags to 0
 * - width to 0
 * - precision to -1 (indicating unset)
 * - specifier to 0
 *
 * @param fmt A pointer to the `t_fmt` structure to initialize.
 * 
 * @ingroup ft_printf
 */
static void	initialize_fmt(t_fmt *fmt)
{
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->specifier = 0;
}

/**
 * @brief Allocates and initializes internal structures for `ft_printf`.
 *
 * Allocates memory for the format specifier structure (`t_fmt`) and
 * initializes both the global print state (`t_pf`) and the format fields.
 *
 * @param pf A pointer to the main `t_pf` structure to initialize.
 *
 * @return 0 on success, or -1 if memory allocation fails.
 * 
 * @see initialize_pf
 * @see initialize_fmt
 * @ingroup ft_printf
 */
int	initialize_printf_structs(t_pf *pf)
{
	initialize_pf(pf);
	pf->fmt = (t_fmt *)malloc(sizeof(t_fmt));
	if (pf->fmt == NULL)
		return (-1);
	initialize_fmt(pf->fmt);
	return (0);
}

/**
 * @brief Checks if a character is a valid format flag for `ft_printf`.
 *
 * Valid flags include:
 * - '#' for alternative form
 * - '0' for zero padding
 * - '-' for left alignment
 * - '+' for always show sign
 * - ' ' (space) for leading space
 *
 * @param c The character to check.
 * @return 1 if the character is a valid flag, 0 otherwise.
 * 
 * @ingroup ft_printf
 */
int	is_valid_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}
