/**
 * @file ft_number_conversion.c
 * @author Toonsa
 * @date 2025/04/05
 * @brief Number-to-string and string-to-number conversion functions.
 *
 * @details
 * This file implements utility functions for converting between numeric
 * types and their string representations, with overflow detection,
 * base formatting, and both signed and unsigned variants.
 *
 * @ingroup number_conversions
 */

#include "libft.h"

/**
 * @brief Checks for overflow when converting a string to a long long integer.
 *
 * @details
 * Evaluates whether appending a digit to @p num would cause it to overflow
 * a signed 32-bit integer, taking into account the current sign.
 *
 * @param num The current number being built.
 * @param digit The current character digit to append.
 * @param sign The number sign (1 for positive, -1 for negative).
 * @return true if overflow would occur, false otherwise.
 *
 * @see ft_atoi
 * @ingroup number_conversions
 */
static bool ft_check_overflow(long long num, char digit, int sign)
{
	long long cutoff;

	if (sign == 1)
		cutoff = INT_MAX / 10;
	else
		cutoff = (-(long long) INT_MIN) / 10;
	if (sign == 1)
	{
		if (num > cutoff || (num == cutoff && (digit - '0') > (INT_MAX % 10)))
			return (true);
	}
	else
	{
		if (-num > -((long long) INT_MIN / 10) ||
		    (-num == -((long long) INT_MIN / 10) &&
		     (digit - '0') > ((-(long long) INT_MIN) % 10)))
			return (true);
	}
	return (false);
}

/**
 * @brief Converts a string to a signed integer.
 *
 * @details
 * Converts the null-terminated string @p str to a `long long` value.
 * Handles optional leading whitespace, sign, and overflow.
 *
 * @param str The string to convert.
 * @return The converted value or `ATOI_ERROR` on overflow.
 *
 * @see ft_check_overflow
 * @see ATOI_ERROR
 * @ingroup number_conversions
 */
long long ft_atoi(const char* str)
{
	long long num;
	int       sign;

	num  = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		if (ft_check_overflow(num, *str, sign))
			return (ATOI_ERROR);
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int) num * sign);
}

/**
 * @brief Converts a string to a `long long` value.
 *
 * @details
 * Similar to `ft_atoi`, but does not cast to int and returns
 * a full `long long` result. Handles whitespace, signs, and overflow.
 *
 * @param str The string to convert.
 * @return The converted value or `ATOI_ERROR` on overflow.
 *
 * @see ft_check_overflow
 * @see ATOI_ERROR
 * @ingroup number_conversions
 */
long long ft_atoll(const char* str)
{
	long long num;
	int       sign;

	num  = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		if (ft_check_overflow(num, *str, sign))
			return (ATOI_ERROR);
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

/**
 * @brief Calculates the number of digits to represent a value in a given base.
 *
 * @details
 * Computes how many characters are needed to express @p n in base @p base.
 * Used internally by `ft_itoa_base`.
 *
 * @param n The number to analyze.
 * @param base The numerical base (2–16).
 * @return The number of digits required to represent @p n.
 *
 * @ingroup number_conversions
 */
static size_t ft_baselen(unsigned long long n, int base)
{
	size_t len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

/**
 * @brief Converts an unsigned integer to a string in a given base.
 *
 * @details
 * Converts the unsigned number @p n to a string in base @p base (2–16).
 * Uses lowercase or uppercase digits based on @p uppercase.
 *
 * @param n The number to convert.
 * @param base The base for conversion (2–16).
 * @param uppercase If 1, use uppercase letters for bases > 10.
 * @return A newly allocated null-terminated string, or NULL on failure.
 *
 * @see ft_baselen
 * @ingroup number_conversions
 */
char* ft_itoa_base(unsigned long long n, int base, int uppercase)
{
	char*  digits;
	char*  str;
	size_t len;

	if (base < 2 || base > 16)
		return (NULL);
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	len = ft_baselen(n, base);
	str = (char*) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = digits[n % base];
		n /= base;
	}
	return (str);
}

/**
 * @brief Converts an integer to a string.
 *
 * @details
 * Allocates and returns a new string representing the integer `n`.
 * Handles negative numbers and returns NULL if allocation fails.
 *
 * @param n The integer to convert.
 * @return A null-terminated string representing `n`, or NULL on failure.
 *
 * @ingroup string_utils
 */
char* ft_itoa(int n)
{
	char*  str;
	long   nb;
	size_t len;

	nb  = n;
	len = (nb <= 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	str = (char*) malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb     = -nb;
	}
	while (nb > 0)
	{
		str[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}

/**
 * @brief Converts an unsigned long long to a decimal string.
 *
 * @details
 * Converts the value @p n to its decimal string representation.
 * A null-terminated string is returned. The caller must free it.
 *
 * @param n The number to convert.
 * @return A dynamically allocated string, or NULL on allocation failure.
 *
 * @ingroup number_conversions
 */
char* ft_utoa(unsigned long long n)
{
	char*              str;
	size_t             len;
	unsigned long long temp_num;

	len      = 1;
	temp_num = n;
	while (temp_num >= 10)
	{
		temp_num /= 10;
		len++;
	}
	str = (char*) malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
