/**
 * @file ft_is_valid_integer.c
 * @author Toonsa
 * @date 2025/01/31
 * @brief Validates whether a string represents a valid `long long` integer.
 *
 * @details
 * This module implements a utility function that determines whether a
 * string is a valid signed decimal integer fitting within the `long long`
 * range. It supports an optional '+' or '-' sign, followed by digits only.
 *
 * The check is purely lexical and does not convert the string unless valid.
 *
 * @ingroup check
 */

 #include "ft_check.h"  // for ft_isdigit

 /**
  * @brief Checks if a numeric string fits within the `long long` range.
  *
  * @details
  * This helper function verifies whether the numeric value represented by
  * the string (without sign prefix) is within the bounds of a signed
  * `long long`, depending on whether it's negative.
  *
  * Uses manual overflow detection logic to avoid undefined behavior.
  *
  * @param str The numeric string to check (must not include the sign).
  * @param negative Indicates if the original number was negative.
  *
  * @return true if the value fits in `long long`, false otherwise.
  *
  * @see ft_isdigit
  * @ingroup check
  */
 static bool	is_in_longlong_range(const char *str, bool negative)
 {
	 unsigned long long	limit;
	 unsigned long long	sum;
	 int					digit;
 
	 if (negative)
		 limit = (unsigned long long)LLONG_MAX + 1ULL;
	 else
		 limit = (unsigned long long)LLONG_MAX;
	 sum = 0;
	 while (*str)
	 {
		 if (!ft_isdigit((unsigned char)*str))
			 return (false);
		 digit = *str - '0';
		 if (sum > (limit - digit) / 10ULL)
			 return (false);
		 sum = sum * 10ULL + digit;
		 str++;
	 }
	 return (true);
 }
 
 /**
  * @brief Validates if a string represents a valid `long long` integer.
  *
  * @details
  * The string may start with a '+' or '-' sign, followed by decimal digits.
  * The function rejects empty strings, non-digit characters, and any
  * numeric values that would overflow a `long long`.
  *
  * @param str Null-terminated string to validate.
  * @return true if valid, false otherwise.
  *
  * @see is_in_longlong_range
  * @ingroup check
  */
 bool	ft_is_valid_integer(const char *str)
 {
	 bool	negative;
 
	 if (!str || !*str)
		 return (false);
	 negative = false;
	 if (*str == '+' || *str == '-')
	 {
		 if (*str == '-')
			 negative = true;
		 str++;
	 }
	 if (!*str)
		 return (false);
	 if (!is_in_longlong_range(str, negative))
		 return (false);
	 return (true);
 }
 