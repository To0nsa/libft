/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlouis <nlouis@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:36:09 by nlouis            #+#    #+#             */
/*   Updated: 2025/03/25 22:56:12 by nlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file char_check.c
 * @brief Character classification functions.
 *
 * This file contains helper functions that test the type of a given character,
 * similar to standard `ctype.h` functions (like `isdigit`, `isalpha`, etc.).
 * These functions are useful when implementing a custom libc (libft).
 * 
 * @author nlouis
 * @date 2024/10/21
 */
#include "libft.h"

/**
 * @brief Checks if a character is an ASCII character.
 * 
 * @param c The character to check.
 * @return 1 if the character is between 0 and 127, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/**
 * @brief Checks if a character is a decimal digit.
 * 
 * @param c The character to check.
 * @return 1 if the character is between '0' and '9', 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief Checks if a character is an alphabetic letter.
 * 
 * @param c The character to check.
 * @return 1 if the character is 'A'-'Z' or 'a'-'z', 0 otherwise.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/**
 * @brief Checks if a character is alphanumeric.
 * 
 * @param c The character to check.
 * @return 1 if the character is a letter or a digit, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}


/**
 * @brief Checks if a character is lowercase.
 * 
 * @param c The character to check.
 * @return 1 if the character is 'a'-'z', 0 otherwise.
 */
int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * @brief Checks if a character is printable.
 * 
 * @param c The character to check.
 * @return 1 if the character is printable (32 to 126), 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/**
 * @brief Checks if a character is a punctuation character.
 * 
 * @param c The character to check.
 * @return 1 if the character is a punctuation character, 0 otherwise.
 */
int	ft_ispunct(int c)
{
	return ((c >= '!' && c <= '/') || (c >= ':' && c <= '@')
		|| (c >= '[' && c <= '`') || (c >= '{' && c <= '~'));
}

/**
 * @brief Checks if a character is a sign ('+' or '-').
 * 
 * @param c The character to check.
 * @return 1 if the character is a sign, 0 otherwise.
 */
int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

/**
 * @brief Checks if a character is uppercase.
 * 
 * @param c The character to check.
 * @return 1 if the character is between 'A' and 'Z', 0 otherwise.
 */
int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/**
 * @brief Checks if a character is a whitespace character.
 * 
 * Recognizes space, tab, newline, vertical tab, form feed, and carriage return.
 *
 * @param c The character to check.
 * @return 1 if the character is a whitespace, 0 otherwise.
 */
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
