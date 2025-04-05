/**
 * @file skip_whitespace.c
 * @author Toonsa
 * @date 2025/04/05
 * @brief Utility functions to skip leading whitespace in C strings.
 *
 * @details
 * This file implements helper functions for parsing strings by skipping
 * over leading whitespace characters. It provides both pointer-based and
 * index-based variants to accommodate different parsing use cases.
 *
 * @ingroup string_utils
 */

 #include "libft.h"

 /**
  * @brief Skips leading whitespace by incrementing a pointer index.
  *
  * @details
  * This function iterates through the @p input string from the position
  * indicated by the index @p *i, incrementing the index until a non-whitespace
  * character is reached. Whitespace is detected using `ft_isspace`.
  *
  * @param input The string to search for whitespace.
  * @param i Pointer to the current index, which will be updated in-place.
  *
  * @see skip_whitespace_ptr
  * @ingroup string_utils
  */
 void	skip_whitespace_index(const char *input, int *i)
 {
	 while (ft_isspace(input[*i]))
		 (*i)++;
 }
 
 /**
  * @brief Returns a pointer to the first non-whitespace character.
  *
  * @details
  * Iterates through the string @p s and returns a pointer to the first
  * character that is not a whitespace character. If all characters are
  * whitespace, returns a pointer to the null-terminator.
  *
  * @param s The string to scan.
  * @return A pointer to the first non-whitespace character, or to '\0'.
  *
  * @see skip_whitespace_index
  * @ingroup string_utils
  */
 char	*skip_whitespace_ptr(const char *s)
 {
	 while (ft_isspace(*s))
		 s++;
	 return ((char *)s);
 }
 