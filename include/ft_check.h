/**
 * @file ft_check.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief Classification and validation functions for characters and strings.
 *
 * @details
 * This module provides custom implementations of standard character
 * classification functions (`isalpha`, `isdigit`, etc.) as well as
 * additional validation helpers for strings (`ft_isstrpositive`,
 * `ft_is_valid_integer`).
 *
 * These functions are useful in parsing, input validation, formatting,
 * and expression evaluation.
 *
 * @ingroup check
 */

 #ifndef FT_CHECK_H
 # define FT_CHECK_H
 
 # include <stdbool.h>  // for bool
 # include <stddef.h>   // for NULL
 # include <limits.h>   // for LLONG_MAX
 
 /**
  * @defgroup check Character and String Classification
  * @brief Custom functions to classify characters or validate string content.
  *
  * @details
  * This group includes replacements and enhancements for standard `<ctype.h>`
  * checks as well as boolean helpers to test string-wide properties
  * (e.g., numeric strings, positivity).
  * 
  * This group includes:
  * - @ref ft_isalnum
  * - @ref ft_isalpha
  * - @ref ft_isascii
  * - @ref ft_isdigit
  * - @ref ft_isprint
  * - @ref ft_ispunct
  * - @ref ft_isspace
  * - @ref ft_islower
  * - @ref ft_isupper
  * - @ref ft_issign
  * - @ref ft_isstrpositive
  * - @ref ft_is_valid_integer
  *
  * @{
  */
 
 // ─────────────────────────────────────────────────────────────
 // Character checks (drop-in replacements for <ctype.h>)
 // ─────────────────────────────────────────────────────────────
 int		ft_isalnum(int c);        ///< Alphanumeric character
 int		ft_isalpha(int c);        ///< Alphabetic character
 int		ft_isascii(int c);        ///< ASCII character (0–127)
 int		ft_isdigit(int c);        ///< Decimal digit (0–9)
 int		ft_isprint(int c);        ///< Printable character (including space)
 int		ft_ispunct(int c);        ///< Printable non-alphanumeric (e.g., punctuation)
 int		ft_isspace(int c);        ///< Whitespace (space, tab, newline, etc.)
 int		ft_islower(int c);        ///< Lowercase letter
 int		ft_isupper(int c);        ///< Uppercase letter
 int		ft_issign(int c);         ///< '+' or '-'
 
 // ─────────────────────────────────────────────────────────────
 // String validation helpers
 // ─────────────────────────────────────────────────────────────
 bool	ft_isstrpositive(const char *str);      ///< Checks if string contains only digits and is > 0
 bool	ft_is_valid_integer(const char *str);   ///< Validates C-style signed integer string format
 
 /** @} */ // end of char_check group
 
 #endif
 
 