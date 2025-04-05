/**
 * @file get_next_line.c
 * @author Toonsa
 * @date 2025/02/25
 * @brief Implementation of the get_next_line function.
 *
 * @details
 * This file implements `get_next_line`, a utility that reads from a file
 * descriptor and returns the next line of input (including `\n` if present).
 * It uses a static buffer indexed by file descriptor to support reading
 * from multiple files simultaneously.
 *
 * @note `BUFFER_SIZE` and `MAX_FD` are defined in ft_file.h.
 *
 * @ingroup file_utils
 */

 #include "libft.h"

 /**
  * @brief Reads from a file descriptor and appends to the remainder buffer.
  *
  * @details
  * Allocates a temporary buffer and appends read data to the remainder until
  * a newline is found or EOF is reached. It handles reallocation and joins
  * partial strings dynamically.
  *
  * @param fd         The file descriptor to read from.
  * @param remainder  Pointer to the pointer holding current remainder.
  *
  * @return Number of bytes read on success, -1 on error.
  *
  * @see ft_strdup
  * @see ft_strchr
  * @see ft_strjoin
  * @ingroup file_utils
  */
 static ssize_t	read_and_store(int fd, char **remainder)
 {
	 ssize_t	bytes_read;
	 char	*buffer;
	 char	*new_remainder;
 
	 if (*remainder == NULL)
		 *remainder = ft_strdup("");
	 buffer = malloc(BUFFER_SIZE + 1);
	 if (!buffer)
		 return (-1);
	 bytes_read = 1;
	 while ((ft_strchr(*remainder, '\n') == NULL) && bytes_read != 0)
	 {
		 bytes_read = read(fd, buffer, BUFFER_SIZE);
		 if (bytes_read == -1)
			 return (free(buffer), -1);
		 buffer[bytes_read] = '\0';
		 new_remainder = ft_strjoin(*remainder, buffer);
		 if (!new_remainder)
			 return (free(buffer), -1);
		 free(*remainder);
		 *remainder = new_remainder;
	 }
	 free(buffer);
	 return (bytes_read);
 }
 
 /**
  * @brief Extracts the next line from the remainder buffer.
  *
  * @details
  * Allocates and returns a new string containing everything from the start
  * of `remainder` up to and including the first newline, or up to the null
  * terminator if no newline is found.
  *
  * @param remainder The remainder buffer.
  * @return New allocated line string, or NULL if empty.
  *
  * @see ft_substr
  * @ingroup file_utils
  */
 static char	*extract_line(char *remainder)
 {
	 size_t	line_len;
	 char	*line;
 
	 line_len = 0;
	 if (!remainder || !remainder[0])
		 return (NULL);
	 while (remainder[line_len] && remainder[line_len] != '\n')
		 line_len++;
	 if (remainder[line_len] == '\n')
		 line_len++;
	 line = ft_substr(remainder, 0, line_len);
	 if (!line)
		 return (NULL);
	 return (line);
 }
 
 /**
  * @brief Updates the remainder buffer after a line has been extracted.
  *
  * @details
  * Frees the old remainder and returns a newly allocated string containing
  * the part of the original string after the first newline.
  *
  * @param remainder The buffer to update.
  * @return A new remainder string, or NULL if nothing is left.
  *
  * @see ft_strlen
  * @see ft_substr
  * @ingroup file_utils
  */
 static char	*update_remainder(char *remainder)
 {
	 char	*new_remainder;
	 size_t	line_len;
	 size_t	remainder_len;
 
	 if (!remainder)
		 return (NULL);
	 line_len = 0;
	 while (remainder[line_len] && remainder[line_len] != '\n')
		 line_len++;
	 if (remainder[line_len] == '\n')
		 line_len++;
	 if (remainder[line_len] == '\0')
	 {
		 free(remainder);
		 return (NULL);
	 }
	 remainder_len = ft_strlen(remainder);
	 new_remainder = ft_substr(remainder, line_len, remainder_len - line_len);
	 free(remainder);
	 if (!new_remainder)
		 return (NULL);
	 return (new_remainder);
 }
 
 /**
  * @brief Reads the next line from a file descriptor.
  *
  * @details
  * This function returns the next line read from `fd`. It uses static storage
  * to preserve context across calls and handles files independently.
  *
  * @param fd The file descriptor to read from.
  * @return The next line, or NULL if EOF or an error occurs.
  *
  * @note Caller is responsible for freeing the returned string.
  * @note Depends on BUFFER_SIZE and MAX_FD being defined.
  *
  * @see read_and_store
  * @see extract_line
  * @see update_remainder
  * @ingroup file_utils
  */
 char	*get_next_line(int fd)
 {
	 static char	*remainder[MAX_FD];
	 char		*line;
	 ssize_t		bytes_read;
 
	 if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		 return (NULL);
	 if (!remainder[fd])
	 {
		 remainder[fd] = ft_strdup("");
		 if (!remainder[fd])
			 return (NULL);
	 }
	 bytes_read = read_and_store(fd, &remainder[fd]);
	 if (bytes_read == -1 || (bytes_read == 0 && remainder[fd][0] == '\0'))
	 {
		 free(remainder[fd]);
		 remainder[fd] = NULL;
		 return (NULL);
	 }
	 line = extract_line(remainder[fd]);
	 if (!line)
		 return (NULL);
	 remainder[fd] = update_remainder(remainder[fd]);
	 return (line);
 }
 