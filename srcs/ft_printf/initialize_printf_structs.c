/**
 * @file initialize_printf_structs.c
 * @brief Initialization helpers for `ft_printf` internal state.
 *
 * @details
 * This module defines utility functions to initialize the data structures
 * used by the custom `ft_printf` implementation:
 * - `t_pf`: main output state tracker
 * - `t_fmt`: format specification context
 *
 * It also includes a function to validate format flags.
 * All structures are reset to default values prior to parsing.
 *
 * @author Toonsa
 * @date 2024/12/01
 * @ingroup ft_printf
 */

 #include "libft.h"

 /**
  * @brief Initializes a `t_pf` (printf state) structure.
  *
  * Sets total written characters, write error, and malloc error
  * tracking fields to zero.
  *
  * @param pf Pointer to the `t_pf` structure to initialize.
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
  * @brief Initializes a `t_fmt` (format specifier) structure.
  *
  * Sets formatting fields to their default values:
  * - `flags = 0`
  * - `width = 0`
  * - `precision = -1` (unset)
  * - `specifier = 0` (null character)
  *
  * @param fmt Pointer to the `t_fmt` structure to initialize.
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
  * @brief Allocates and initializes the structures required by `ft_printf`.
  *
  * This function sets up the main state structure (`t_pf`) and allocates
  * a `t_fmt` format descriptor. All fields are initialized to their default
  * values. If allocation fails, returns -1.
  *
  * @param pf Pointer to the `t_pf` structure that will be initialized.
  *
  * @return 0 on success, or -1 if allocation fails.
  *
  * @see initialize_pf
  * @see initialize_fmt
  * @ingroup ft_printf
  */
 int	initialize_printf_structs(t_pf *pf)
 {
	 initialize_pf(pf);
	 pf->fmt = (t_fmt *)malloc(sizeof(t_fmt));
	 if (!pf->fmt)
		 return (-1);
	 initialize_fmt(pf->fmt);
	 return (0);
 }
 
 /**
  * @brief Checks if a character is a valid format flag.
  *
  * Recognized flags include:
  * - `#`: alternate form
  * - `0`: zero padding
  * - `-`: left-justify
  * - `+`: show plus sign
  * - `' '` (space): leading space for positive numbers
  *
  * @param c The character to evaluate.
  *
  * @return 1 if the character is a valid flag, 0 otherwise.
  *
  * @ingroup ft_printf
  */
 int	is_valid_flag(char c)
 {
	 return (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
 }
 