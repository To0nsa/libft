/**
 * @file ft_split.c
 * @author Toonsa
 * @date 2025/04/05
 * @brief Splits a string into substrings using a single delimiter character.
 *
 * @details
 * This file implements the `ft_split` function, which breaks a string
 * into an array of substrings based on a single delimiter character.
 * Substrings are dynamically allocated, and the output is a NULL-terminated
 * array. Internal helpers handle word counting and array filling.
 *
 * @ingroup string_utils
 */

 #include "libft.h"

 /**
  * @brief Counts how many substrings will result from splitting.
  *
  * @details
  * Traverses the input string and counts how many substrings (non-empty
  * sequences not interrupted by the delimiter) will be generated.
  *
  * @param str The input string to scan.
  * @param c The delimiter character.
  * @return The number of substrings (words) in the input.
  */
 static size_t	ft_w_count(const char *str, char c)
 {
	 size_t	w_count;
	 int	in_word;
 
	 w_count = 0;
	 in_word = 0;
	 while (*str)
	 {
		 if (*str != c && in_word == 0)
		 {
			 w_count++;
			 in_word = 1;
		 }
		 else if (*str == c)
			 in_word = 0;
		 str++;
	 }
	 return (w_count);
 }
 
 /**
  * @brief Fills the output array with substrings from input.
  *
  * @details
  * Allocates substrings from @p s using `ft_substr` and stores them in
  * the provided array. The array is NULL-terminated.
  * On allocation failure, previously allocated substrings are freed.
  *
  * @param array The output array of substrings.
  * @param s The input string to split.
  * @param c The delimiter character.
  * @param w_count The number of substrings to extract.
  * @return 1 on success, 0 on failure.
  *
  * @see ft_substr
  * @see ft_free_array
  */
 static int	ft_fill_array(char **array, const char *s, char c, size_t w_count)
 {
	 size_t	i;
	 size_t	word_len;
 
	 i = 0;
	 while (i < w_count)
	 {
		 while (*s == c)
			 s++;
		 word_len = 0;
		 while (s[word_len] && s[word_len] != c)
			 word_len++;
		 array[i] = ft_substr(s, 0, word_len);
		 if (!array[i])
		 {
			 ft_free_array((void **)array);
			 return (0);
		 }
		 s += word_len;
		 i++;
	 }
	 array[i] = NULL;
	 return (1);
 }
 
 /**
  * @brief Splits a string into substrings based on a delimiter character.
  *
  * @details
  * Splits the input string @p s into substrings separated by the delimiter
  * @p c. The resulting substrings are stored in a newly allocated
  * NULL-terminated array.
  *
  * @param s The string to split.
  * @param c The delimiter character.
  * @return A newly allocated array of substrings, or NULL on failure.
  *
  * @note The input string is not modified. Each substring and the array
  * itself must be freed manually using `ft_free_array`.
  *
  * @see ft_w_count
  * @see ft_fill_array
  * @see ft_substr
  * @see ft_free_array
  * @ingroup string_utils
  */
 char	**ft_split(const char *s, char c)
 {
	 char		**array;
	 size_t		w_count;
 
	 if (!s)
		 return (NULL);
	 w_count = ft_w_count(s, c);
	 array = (char **)ft_calloc(w_count + 1, sizeof(char *));
	 if (!array)
		 return (NULL);
	 if (!ft_fill_array(array, s, c, w_count))
	 {
		 free(array);
		 return (NULL);
	 }
	 return (array);
 }
 