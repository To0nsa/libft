/**
 * @file ft_strtrim.c
 * @author Toonsa
 * @date 2025/04/05
 * @brief Trims characters from the beginning and end of a string.
 *
 * @details
 * This file implements the `ft_strtrim` function, which removes all leading
 * and trailing characters from a string based on a given set. It also
 * defines helper functions to locate trim boundaries efficiently.
 *
 * @ingroup string_utils
 */

 #include "libft.h"

 /**
  * @brief Checks if a character is present in a given set.
  *
  * @details
  * Iterates through the @p set and returns 1 if character @p c is found,
  * 0 otherwise.
  *
  * @param c The character to check.
  * @param set The null-terminated string containing the set of characters.
  * @return 1 if @p c is in @p set, 0 otherwise.
  */
 static int	ft_is_in_set(char c, const char *set)
 {
	 size_t	i;
 
	 i = 0;
	 while (set[i])
	 {
		 if (set[i] == c)
			 return (1);
		 i++;
	 }
	 return (0);
 }
 
 /**
  * @brief Finds the starting index after trimming leading characters.
  *
  * @details
  * Scans from the beginning of @p s1 and returns the index of the first
  * character not included in @p set.
  *
  * @param s1 The string to trim.
  * @param set The set of characters to remove.
  * @return Index of the first non-trimmed character.
  */
 static size_t	ft_trim_start(const char *s1, const char *set)
 {
	 size_t	start;
 
	 start = 0;
	 while (s1[start] && ft_is_in_set(s1[start], set))
		 start++;
	 return (start);
 }
 
 /**
  * @brief Finds the ending index before trimming trailing characters.
  *
  * @details
  * Scans backward from the end of @p s1 and returns the index of the
  * last character not in @p set + 1.
  *
  * @param s1 The string to trim.
  * @param set The set of characters to remove.
  * @return Index of the first trailing character (exclusive).
  */
 static size_t	ft_trim_end(const char *s1, const char *set)
 {
	 size_t	end;
 
	 end = ft_strlen(s1);
	 while (end > 0 && ft_is_in_set(s1[end - 1], set))
		 end--;
	 return (end);
 }
 
 /**
  * @brief Trims characters from both ends of a string.
  *
  * @details
  * Allocates and returns a new string derived from @p s1 with all characters
  * found in @p set removed from both the beginning and the end.
  * The returned string is NULL-terminated and dynamically allocated.
  *
  * @param s1 The original null-terminated string to trim.
  * @param set The set of characters to remove.
  * @return A newly allocated trimmed string, or NULL on allocation failure.
  *
  * @note If the trimmed result is empty, the function returns a string
  * containing only '\0'. The caller is responsible for freeing the result.
  *
  * @see ft_trim_start
  * @see ft_trim_end
  * @see ft_strlcpy
  * @ingroup string_utils
  */
 char	*ft_strtrim(const char *s1, const char *set)
 {
	 size_t	start;
	 size_t	end;
	 char	*trimmed_str;
	 size_t	copy_size;
 
	 if (!s1 || !set)
		 return (NULL);
	 start = ft_trim_start(s1, set);
	 end = ft_trim_end(s1, set);
	 copy_size = end - start;
	 if (start >= end)
	 {
		 trimmed_str = (char *)malloc(sizeof(char));
		 if (!trimmed_str)
			 return (NULL);
		 trimmed_str[0] = '\0';
		 return (trimmed_str);
	 }
	 trimmed_str = (char *)malloc((copy_size + 1) * sizeof(char));
	 if (!trimmed_str)
		 return (NULL);
	 ft_strlcpy(trimmed_str, s1 + start, copy_size + 1);
	 return (trimmed_str);
 }
 