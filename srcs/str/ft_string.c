#include "libft.h"

/**
 * @file ft_string.c
 * @author Toonsa
 * @date 2025/04/05
 * @brief Returns the number of characters in a string.
 *
 * Iterates through the given null-terminated string to determine
 * its length (not including the terminating `\0`).
 *
 * @param str The string whose length is to be calculated.
 * @return The number of characters before the null terminator.
 *
 * @ingroup string_utils
 */
size_t ft_strlen(const char* str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * @brief Appends the `src` string to the end of the `dest` string.
 *
 * This function assumes that `dest` points to a buffer large enough to hold
 * the resulting string, including the null terminator.
 *
 * @param dest The destination string to which `src` will be appended.
 * @param src The source string to append.
 * @return A pointer to the destination string (`dest`).
 *
 * @note The behavior is undefined if the destination buffer is not large
 *       enough to contain the result.
 *
 * @ingroup string_utils
 */
char* ft_strcat(char* dest, const char* src)
{
	char* dest_ptr;

	dest_ptr = dest;
	while (*dest_ptr)
		dest_ptr++;
	while (*src)
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}
	*dest_ptr = '\0';
	return (dest);
}

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * Searches for the first occurrence of the character `c` in the string `str`.
 * The terminating null byte (`\0`) is considered part of the string.
 *
 * @param str The null-terminated string to search in.
 * @param c The character to search for, interpreted as an unsigned char.
 * @return A pointer to the first occurrence of `c` in `str`,
 *         or NULL if `c` is not found.
 *
 * @ingroup string_utils
 */
char* ft_strchr(const char* str, int c)
{
	while (*str)
	{
		if (*str == (char) c)
			return ((char*) str);
		str++;
	}
	if ((char) c == '\0')
		return ((char*) str);
	return (NULL);
}

/**
 * @brief Compares two strings lexicographically.
 *
 * This function compares the characters of `s1` and `s2` one by one.
 * The comparison stops at the first differing character or when a null byte
 * is reached.
 *
 * @param s1 Pointer to the first null-terminated string.
 * @param s2 Pointer to the second null-terminated string.
 * @return An integer less than, equal to, or greater than 0 if `s1` is found
 *         to be less than, equal to, or greater than `s2`, respectively.
 *
 * @note The comparison is done using unsigned char values.
 *
 * @see ft_strncmp
 * @see ft_strcmp
 * @ingroup string_utils
 */
int ft_strcmp(const char* s1, const char* s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

/**
 * @brief Compares two strings up to `n` characters.
 *
 * This function compares the first `n` characters of the strings
 * `s1` and `s2`. The comparison is done using unsigned characters.
 *
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @param n  Maximum number of characters to compare.
 *
 * @return An integer less than, equal to, or greater than 0 if `s1`
 *         is found, respectively, to be less than, to match, or be
 *         greater than `s2`.
 *
 * @note The comparison stops when a difference is found, a null byte
 *       is encountered, or `n` characters have been compared.
 *
 * @ingroup string_utils
 */
int ft_strncmp(const char* s1, const char* s2, size_t n)
{
	while (n > 0 && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

/**
 * @brief Compares two strings lexicographically.
 *
 * This function compares the characters of `s1` and `s2` one by one.
 * The comparison stops at the first differing character or when a null byte
 * is reached.
 *
 * @param s1 Pointer to the first null-terminated string.
 * @param s2 Pointer to the second null-terminated string.
 * @return An integer less than, equal to, or greater than 0 if `s1` is found
 *         to be less than, equal to, or greater than `s2`, respectively.
 *
 * @ingroup string_utils
 */
char* ft_strcpy(char* dst, const char* src)
{
	char* ret;

	ret = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}

/**
 * @brief Copies a string from `src` to `dest`, up to `size` - 1 characters.
 *
 * Copies up to `size - 1` characters from the null-terminated string `src`
 * to `dest`, null-terminating the result. If `size` is 0, nothing is written
 * to `dest`, but the length of `src` is still returned.
 *
 * @param dest Destination buffer.
 * @param src Source null-terminated string to copy.
 * @param size Total size of destination buffer.
 *
 * @return The length of `src`. This allows detection of truncation:
 *         if the return value is >= `size`, truncation occurred.
 *
 * @ingroup string_utils
 */
size_t ft_strlcpy(char* dest, const char* src, size_t size)
{
	size_t i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/**
 * @brief Allocates and duplicates a null-terminated string.
 *
 * Allocates memory for a copy of the string `src`, copies its contents
 * (including the null terminator), and returns a pointer to the new string.
 *
 * @param src The source string to duplicate.
 * @return A pointer to the newly allocated string, or NULL on allocation
 * failure.
 *
 * @see ft_strlcpy
 * @see ft_strlen
 * @ingroup string_utils
 */
char* ft_strdup(const char* src)
{
	char*  copy;
	size_t src_len;

	src_len = ft_strlen(src);
	copy    = (char*) malloc((src_len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, src_len + 1);
	return (copy);
}

/**
 * @brief Applies a function to each character of a string, passing its index.
 *
 * Iterates over the string `s` and applies the function `f` to each character.
 * The function receives the index of the character and a pointer to it,
 * allowing in-place modification.
 *
 * @param s The string to iterate over.
 * @param f The function to apply to each character.
 *
 * @note If either `s` or `f` is NULL, the function does nothing.
 *
 * @ingroup string_utils
 */
void ft_striteri(char* s, void (*f)(unsigned int, char*))
{
	size_t i;

	if (!s || !f)
		return;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * Allocates a new string containing the contents of `s1` followed by `s2`.
 * If either string is NULL, it is treated as an empty string.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return A new string containing the concatenation of `s1` and `s2`,
 *         or NULL if memory allocation fails.
 *
 * @note The caller is responsible for freeing the returned string.
 *
 * @see ft_strlen
 * @see ft_strlcpy
 * @ingroup string_utils
 */
char* ft_strjoin(const char* s1, const char* s2)
{
	char*  new_str;
	size_t s1_len;
	size_t s2_len;
	size_t total_len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1_len    = ft_strlen(s1);
	s2_len    = ft_strlen(s2);
	total_len = s1_len + s2_len;
	new_str   = (char*) malloc((total_len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}

/**
 * @brief Concatenates `src` to the end of `dest` while ensuring
 * null-termination.
 *
 * This function appends the `src` string to the end of the `dest` string.
 * It ensures that the result fits within the buffer size given by `size`,
 * including the null-terminator. If `size` is less than or equal to the
 * length of `dest`, the function returns `size + strlen(src)` without
 * appending.
 *
 * @param dest The destination buffer.
 * @param src The source string to append.
 * @param size The total size of the destination buffer.
 *
 * @return The total length of the string it tried to create:
 *         `strlen(dest) + strlen(src)`.
 *         This value can be used to detect truncation.
 *
 * @see ft_strlen
 * @see ft_strlcpy
 * @ingroup string_utils
 */
size_t ft_strlcat(char* dest, const char* src, size_t size)
{
	size_t dest_len;
	size_t src_len;
	size_t total_len;
	size_t space_left;

	dest_len = ft_strlen(dest);
	src_len  = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	total_len  = dest_len + src_len;
	space_left = size - dest_len;
	ft_strlcpy(dest + dest_len, src, space_left);
	return (total_len);
}

/**
 * @brief Applies a function to each character of a string to
 *        create a new string.
 *
 * Allocates a new string where each character is the result of
 * applying the given function `f` to the corresponding character
 * of the input string `s`. The function `f` receives the index
 * of each character as its first argument.
 *
 * @param s The original null-terminated string to map.
 * @param f The function to apply to each character, receiving
 *          the index and the character.
 *
 * @return A new string with transformed characters, or NULL if
 *         allocation fails or if input is NULL.
 *
 * @note The returned string must be freed by the caller.
 *
 * @ingroup string_utils
 */
char* ft_strmapi(char const* s, char (*f)(unsigned int, char))
{
	size_t len;
	size_t i;
	char*  new_str;

	if (!s || !f)
		return (NULL);
	len     = ft_strlen(s);
	new_str = (char*) malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/**
 * @brief Creates a copy of a string, up to `n` characters.
 *
 * This function allocates memory and copies at most `n` characters
 * from the string `src` to a new string. The new string is always
 * null-terminated.
 *
 * @param src The source string to duplicate.
 * @param n   The maximum number of characters to copy.
 *
 * @return A pointer to the newly allocated string, or NULL if memory
 *         allocation fails.
 *
 * @see ft_strlcpy
 * @see ft_strlen
 * @ingroup string_utils
 */
char* ft_strndup(const char* src, size_t n)
{
	char*  copy;
	size_t src_len;

	src_len = ft_strlen(src);
	if (n < src_len)
		src_len = n;
	copy = (char*) malloc((src_len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, src_len + 1);
	return (copy);
}

/**
 * @brief Searches for a substring in a string within a max length.
 *
 * This function searches for the first occurrence of the null-terminated
 * string `little` in the string `big`, where not more than `len` characters
 * are searched. Characters after a `\0` character are not searched.
 *
 * If `little` is an empty string, `big` is returned. If `little` occurs
 * nowhere in `big` within the first `len` characters, NULL is returned.
 *
 * @param big    The main string to be searched.
 * @param little The substring to search for.
 * @param len    The maximum number of characters to search in `big`.
 *
 * @return A pointer to the first occurrence of `little` in `big` within
 *         `len` characters, or NULL if not found.
 *
 * @ingroup string_utils
 */
char* ft_strnstr(const char* big, const char* little, size_t len)
{
	size_t i;
	size_t j;

	if (*little == '\0')
		return ((char*) big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && i + j < len && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char*) big + i);
		i++;
	}
	return (NULL);
}

/**
 * @brief Returns a pointer to the last occurrence of a character in a string.
 *
 * Scans the string `str` for the last occurrence of the character `c`
 * (interpreted as an unsigned char). If found, a pointer to the character
 * is returned. If not, NULL is returned.
 *
 * If `c` is '\0', a pointer to the null terminator at the end of the string
 * is returned.
 *
 * @param str The null-terminated string to be searched.
 * @param c   The character to search for (casted to `unsigned char`).
 *
 * @return A pointer to the last occurrence of `c` in `str`, or NULL if not
 *         found.
 *
 * @ingroup string_utils
 */
char* ft_strrchr(const char* str, int c)
{
	char* last_occurrence;

	last_occurrence = NULL;
	while (*str)
	{
		if (*str == (char) c)
			last_occurrence = (char*) str;
		str++;
	}
	if ((char) c == '\0')
		return ((char*) str);
	return (last_occurrence);
}

/**
 * @brief Extracts a substring from a string.
 *
 * Allocates and returns a new string, which is a substring of `s` starting from
 * index `start` and up to `len` characters long. If `start` is greater than or
 * equal to the length of `s`, an empty string is returned. The length of the
 * returned substring is either `len` or the remaining length from `start`,
 * whichever is smaller.
 *
 * @param s The source string.
 * @param start The starting index in the source string.
 * @param len The maximum number of characters to copy.
 *
 * @return A newly allocated string containing the substring, or NULL if memory
 * allocation fails. If `start` is out of bounds, an empty string is returned.
 *
 * @see ft_strlen
 * @see ft_strlcpy
 * @ingroup string_utils
 */
char* ft_substr(const char* s, unsigned int start, size_t len)
{
	char*  substr;
	size_t str_len;
	size_t max_len;

	if (s == NULL)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		substr = (char*) malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	max_len = str_len - start;
	if (max_len > len)
		max_len = len;
	substr = (char*) malloc((max_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, max_len + 1);
	return (substr);
}

/**
 * @brief Converts a character to lowercase.
 *
 * If the character `c` is an uppercase letter (between 'A' and 'Z'),
 * it is converted to its lowercase equivalent by adding the difference
 * between the ASCII values of 'a' and 'A'. If `c` is not an uppercase
 * letter, the function returns `c` unchanged.
 *
 * @param c The character to convert.
 *
 * @return The lowercase version of `c` if it is an uppercase letter;
 *         otherwise, returns `c` unchanged.
 *
 * @see ft_toupper
 * @ingroup string_utils
 */
int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + ('a' - 'A');
	return (c);
}

/**
 * @brief Converts a character to uppercase.
 *
 * If the character `c` is a lowercase letter (between 'a' and 'z'),
 * it is converted to its uppercase equivalent by subtracting the
 * difference between the ASCII values of 'a' and 'A'. If `c` is not
 * a lowercase letter, the function returns `c` unchanged.
 *
 * @param c The character to convert.
 *
 * @return The uppercase version of `c` if it is a lowercase letter;
 *         otherwise, returns `c` unchanged.
 *
 * @see ft_tolower
 * @ingroup char_check
 */
int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}