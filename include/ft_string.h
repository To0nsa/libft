/**
 * @file ft_string.h
 * @author Toonsa
 * @date 2025/04/05
 * @brief String manipulation utility functions.
 *
 * @details
 * This header declares utility functions for handling and transforming
 * C strings. It includes operations such as copying, trimming, joining,
 * splitting, and case conversion.
 *
 * These functions aim to replicate or extend the functionality of the
 * C standard library with additional flexibility and safety.
 *
 * @ingroup string_utils
 */

 #ifndef FT_STRING_H
 # define FT_STRING_H
 
 # include <stddef.h> // for size_t
 
 /**
  * @defgroup string_utils String Manipulation Utilities
  * @brief Functions for handling and manipulating C strings.
  *
  * @details
  * This group includes common string operations such as copying,
  * concatenation, trimming, splitting, searching, and case conversion.
  *
  * Useful for tasks like:
  * - Extracting substrings
  * - Skipping whitespace
  * - Finding characters or substrings
  * - Transforming string content
  *
  * @{
  */
 
 char		*ft_strcat(char *dest, const char *src);
 char		**ft_split_charset(char *s, char *charset);
 char		**ft_split(const char *s, char c);
 char		*ft_strchr(const char *str, int c);
 char		*ft_strcpy(char *dst, const char *src);
 char		*ft_strdup(const char *src);
 void		ft_striteri(char *s, void (*f)(unsigned int, char*));
 char		*ft_strjoin(const char *s1, const char *s2);
 char		*ft_strjoin_and_free(char *s1, char *s2, int free_s1, int free_s2);
 size_t		ft_strlcat(char *dest, const char *src, size_t size);
 size_t		ft_strlcpy(char *dest, const char *src, size_t size);
 size_t		ft_strlen(const char *str);
 char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
 int		ft_strcmp(const char *s1, const char *s2);
 int		ft_strncmp(const char *s1, const char *s2, size_t n);
 char		*ft_strndup(const char *src, size_t n);
 char		*ft_strnstr(const char *big, const char *little, size_t len);
 char		*ft_strrchr(const char *str, int c);
 char		*ft_strtrim(const char *s1, const char *set);
 char		*ft_substr(const char *s, unsigned int start, size_t len);
 int		ft_tolower(int c);
 int		ft_toupper(int c);
 void		skip_whitespace_index(const char *input, int *i);
 char		*skip_whitespace_ptr(const char *s);
 
 /** @} */ // end of string_utils group
 
 #endif
 