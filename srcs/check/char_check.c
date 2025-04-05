/**
 * @file check.c
 * @author Toonsa
 * @date 2024/10/21
 * @brief Character and string classification functions.
 *
 * @details
 * This module provides implementations of character-checking utilities
 * similar to standard `<ctype.h>` functions, along with additional helpers
 * for validating specific string formats (e.g. numeric positivity).
 *
 * These are part of the `check` group in libft.
 *
 * @ingroup check
 */

 #include "ft_check.h"

 /**
  * @brief Checks if a character is an ASCII character.
  *
  * @param c Character to check.
  * @return 1 if ASCII (0–127), otherwise 0.
  * @ingroup check
  */
 int	ft_isascii(int c)
 {
	 return (c >= 0 && c <= 127);
 }
 
 /**
  * @brief Checks if a character is a decimal digit.
  *
  * @param c Character to check.
  * @return 1 if '0'–'9', otherwise 0.
  * @ingroup check
  */
 int	ft_isdigit(int c)
 {
	 return (c >= '0' && c <= '9');
 }
 
 /**
  * @brief Checks if a character is an alphabetic letter.
  *
  * @param c Character to check.
  * @return 1 if 'A'–'Z' or 'a'–'z', otherwise 0.
  * @ingroup check
  */
 int	ft_isalpha(int c)
 {
	 return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
 }
 
 /**
  * @brief Checks if a character is alphanumeric.
  *
  * @param c Character to check.
  * @return 1 if alphabetic or digit, otherwise 0.
  * @ingroup check
  */
 int	ft_isalnum(int c)
 {
	 return (ft_isalpha(c) || ft_isdigit(c));
 }
 
 /**
  * @brief Checks if a character is lowercase.
  *
  * @param c Character to check.
  * @return 1 if 'a'–'z', otherwise 0.
  * @ingroup check
  */
 int	ft_islower(int c)
 {
	 return (c >= 'a' && c <= 'z');
 }
 
 /**
  * @brief Checks if a character is uppercase.
  *
  * @param c Character to check.
  * @return 1 if 'A'–'Z', otherwise 0.
  * @ingroup check
  */
 int	ft_isupper(int c)
 {
	 return (c >= 'A' && c <= 'Z');
 }
 
 /**
  * @brief Checks if a character is printable.
  *
  * @param c Character to check.
  * @return 1 if printable (32–126), otherwise 0.
  * @ingroup check
  */
 int	ft_isprint(int c)
 {
	 return (c >= 32 && c <= 126);
 }
 
 /**
  * @brief Checks if a character is a punctuation mark.
  *
  * @param c Character to check.
  * @return 1 if punctuation, otherwise 0.
  * @ingroup check
  */
 int	ft_ispunct(int c)
 {
	 return ((c >= '!' && c <= '/') || (c >= ':' && c <= '@')
		 || (c >= '[' && c <= '`') || (c >= '{' && c <= '~'));
 }
 
 /**
  * @brief Checks if a character is a whitespace character.
  *
  * Recognized: space, tab, newline, vertical tab, form feed, carriage return.
  *
  * @param c Character to check.
  * @return 1 if whitespace, otherwise 0.
  * @ingroup check
  */
 int	ft_isspace(int c)
 {
	 return (c == ' ' || (c >= '\t' && c <= '\r'));
 }
 
 /**
  * @brief Checks if a character is a sign symbol.
  *
  * @param c Character to check.
  * @return 1 if '+' or '-', otherwise 0.
  * @ingroup check
  */
 int	ft_issign(int c)
 {
	 return (c == '-' || c == '+');
 }
 
 /**
  * @brief Checks if a string represents a positive number.
  *
  * @details
  * Returns 1 if the string exists, is non-empty, and does not start with '-'.
  *
  * @param str Null-terminated string to check.
  * @return 1 if positive, otherwise 0.
  * @ingroup check
  */
 bool	ft_isstrpositive(const char *str)
 {
	 if (!str || *str == '\0')
		 return (0);
	 if (*str == '-')
		 return (0);
	 return (1);
 }
 