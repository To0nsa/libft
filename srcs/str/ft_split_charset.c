/**
 * @file ft_split_charset.c
 * @author Toonsa
 * @date 2025/02/08
 * @brief Splits a string into substrings based on a set of delimiters.
 *
 * @details
 * This file provides the implementation of `ft_split_charset`, a string
 * utility that splits a C string into substrings using a set of delimiter
 * characters (charset). Each resulting substring is dynamically allocated
 * and returned as part of a NULL-terminated array.
 *
 * Internal helper functions:
 * - `ft_is_charset`: checks if a character belongs to a charset.
 * - `ft_w_count_charset`: counts how many substrings will be created.
 * - `ft_fill_array_charset`: populates the output array with substrings.
 *
 * @ingroup string_utils
 */

 #include "libft.h"

 /**
  * @brief Checks if a character belongs to a charset.
  * 
  * @details
  * Iterates through the charset and returns 1 if the character @p c
  * is found. Otherwise, returns 0.
  *
  * @param c The character to check.
  * @param charset The set of delimiter characters.
  * @return 1 if the character is in the charset, 0 otherwise.
  */
 static int	ft_is_charset(char c, const char *charset)
 {
	 while (*charset)
	 {
		 if (c == *charset)
			 return (1);
		 charset++;
	 }
	 return (0);
 }
 
 /**
  * @brief Counts the number of substrings in a split.
  * 
  * @details
  * Traverses the input string and counts how many substrings would result
  * from a split based on the given charset.
  *
  * @param str The input string to split.
  * @param charset The set of delimiter characters.
  * @return The number of expected substrings.
  */
 static size_t	ft_w_count_charset(char *str, char *charset)
 {
	 size_t	count;
	 int		in_field;
 
	 count = 0;
	 in_field = 1;
	 while (*str)
	 {
		 if (ft_is_charset(*str, charset))
		 {
			 count++;
			 in_field = 1;
		 }
		 else if (in_field)
		 {
			 in_field = 0;
		 }
		 str++;
	 }
	 return (count + 1);
 }
 
 /**
  * @brief Fills an array of substrings from the input string.
  * 
  * @details
  * Allocates and copies substrings from @p s into the @p array using
  * the set of delimiter characters. If allocation fails at any point,
  * previously allocated substrings are freed.
  *
  * @param array The output array of substrings.
  * @param s The input string to split.
  * @param charset The set of delimiter characters.
  * @param field_count The number of substrings to extract.
  * @return 1 on success, 0 on allocation failure.
  *
  * @see ft_substr
  * @see ft_free_array
  */
 static int	ft_fill_array_charset(char **array, char *s,
								 char *charset, size_t field_count)
 {
	 size_t	i;
	 size_t	field_len;
 
	 i = 0;
	 while (i < field_count)
	 {
		 field_len = 0;
		 while (s[field_len] && !ft_is_charset(s[field_len], charset))
			 field_len++;
		 array[i] = ft_substr(s, 0, field_len);
		 if (!array[i])
		 {
			 ft_free_array((void **)array);
			 return (0);
		 }
		 s += field_len;
		 if (*s)
			 s++;
		 i++;
	 }
	 array[i] = NULL;
	 return (1);
 }
 
 /**
  * @brief Splits a string into substrings based on a character set.
  * 
  * @details
  * This function splits the input string @p s into substrings using
  * the set of delimiter characters defined in @p charset. Each
  * substring is allocated dynamically and stored in a NULL-terminated
  * array.
  *
  * @param s The string to split.
  * @param charset The set of delimiter characters.
  * @return A newly allocated array of substrings, or NULL on error.
  *
  * @see ft_w_count_charset
  * @see ft_fill_array_charset
  * @see ft_free_array
  * @ingroup string_utils
  */
 char	**ft_split_charset(char *s, char *charset)
 {
	 char		**array;
	 size_t		field_count;
 
	 if (!s || !charset)
		 return (NULL);
	 field_count = ft_w_count_charset(s, charset);
	 array = (char **)ft_calloc(field_count + 1, sizeof(char *));
	 if (!array)
		 return (NULL);
	 if (!ft_fill_array_charset(array, s, charset, field_count))
	 {
		 free(array);
		 return (NULL);
	 }
	 return (array);
 }
 