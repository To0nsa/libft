/**
 * @file write_safely.c
 * @brief Safe low-level write utilities for ft_printf.
 *
 * @details
 * This file implements safe wrappers around the `write` system call
 * used by `ft_printf`. It ensures that:
 * - All bytes are written even if the syscall is interrupted
 * - Errors are tracked through the `t_pf` structure
 * - Output progress (`total`) is updated reliably
 *
 * These utilities are essential for robust and portable output handling
 * when implementing a printf-like function.
 *
 * @author Toonsa
 * @date 2024/11/30
 * @ingroup ft_printf
 */

 #include "libft.h"

 /**
  * @brief Safely writes a null-terminated string to a file descriptor.
  *
  * @details
  * This function ensures the full content of `str` is written to `fd`,
  * handling partial writes and interruptions caused by signals (`EINTR`).
  * Updates the `total` field in `t_pf` and sets `write_error` on failure.
  *
  * @param fd File descriptor to write to.
  * @param str Null-terminated string to write.
  * @param pf Pointer to printf state context (`t_pf`).
  *
  * @see ft_strlen
  * @ingroup ft_printf
  */
 void	write_safely(int fd, char *str, t_pf *pf)
 {
	 ssize_t	bytes_written;
	 size_t	total_written;
	 size_t	len;
 
	 if (str == NULL)
		 return ;
	 total_written = 0;
	 len = ft_strlen(str);
	 while (total_written < len)
	 {
		 bytes_written = write(fd, str + total_written, len - total_written);
		 if (bytes_written == -1)
		 {
			 if (errno == EINTR)
				 continue ;
			 pf->write_error = 1;
			 return ;
		 }
		 total_written += bytes_written;
	 }
	 pf->total += total_written;
 }
 
 /**
  * @brief Safely writes `len` bytes from a string to a file descriptor.
  *
  * @details
  * Unlike `write_safely`, this function writes a fixed number of bytes
  * (useful for non-null-terminated data). Handles `EINTR` and write errors.
  *
  * @param fd File descriptor to write to.
  * @param str Buffer containing data to write.
  * @param len Number of bytes to write.
  * @param pf Pointer to printf state context (`t_pf`).
  *
  * @ingroup ft_printf
  */
 void	write_safely_len(int fd, char *str, size_t len, t_pf *pf)
 {
	 ssize_t	bytes_written;
	 size_t	total_written;
 
	 if (str == NULL)
		 return ;
	 total_written = 0;
	 while (total_written < len)
	 {
		 bytes_written = write(fd, str + total_written, len - total_written);
		 if (bytes_written == -1)
		 {
			 if (errno == EINTR)
				 continue ;
			 pf->write_error = 1;
			 return ;
		 }
		 total_written += bytes_written;
	 }
	 pf->total += total_written;
 }
 
 /**
  * @brief Safely writes a single character to a file descriptor.
  *
  * @details
  * Attempts to write `c` to `fd`. If interrupted (`EINTR`), retries.
  * Updates total byte count or sets write error in `pf` on failure.
  *
  * @param fd File descriptor to write to.
  * @param c Character to write.
  * @param pf Pointer to printf state context (`t_pf`).
  *
  * @ingroup ft_printf
  */
 void	write_char_safely(int fd, char c, t_pf *pf)
 {
	 ssize_t	bytes_written;
 
	 bytes_written = write(fd, &c, 1);
	 if (bytes_written == -1)
	 {
		 if (errno == EINTR)
		 {
			 write_char_safely(fd, c, pf);
			 return ;
		 }
		 pf->write_error = 1;
		 return ;
	 }
	 pf->total += bytes_written;
 }
 