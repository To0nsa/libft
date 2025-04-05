/**
 * @file setup_format.c
 * @brief Parses format specifications for ft_printf.
 *
 * @details
 * This module extracts formatting instructions (flags, width,
 * precision, and specifier) from the format string and stores them
 * into a `t_fmt` structure for use by the `ft_printf` handlers.
 *
 * Supported flags: `#`, `0`, `-`, `+`, ` `  
 * Supported specifiers: `%`, `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`
 *
 * @author Toonsa
 * @date 2024/10/15
 * @ingroup ft_printf
 */

 #include "libft.h"

 /**
  * @brief Parses format flags and sets corresponding bits.
  *
  * Flags include: `#`, `0`, `-`, `+`, and space.
  *
  * @param format Format string pointer (will be advanced).
  * @param fmt Target format context.
  *
  * @see is_valid_flag
  * @ingroup ft_printf
  */
 static void	parse_flags(const char **format, t_fmt *fmt)
 {
	 while (**format && is_valid_flag(**format))
	 {
		 if (**format == '#')
			 fmt->flags |= FLAG_HASH;
		 else if (**format == '0')
			 fmt->flags |= FLAG_ZERO;
		 else if (**format == '-')
			 fmt->flags |= FLAG_MINUS;
		 else if (**format == '+')
			 fmt->flags |= FLAG_PLUS;
		 else if (**format == ' ')
			 fmt->flags |= FLAG_SPACE;
		 (*format)++;
	 }
 }
 
 /**
  * @brief Parses field width (e.g., `%10d`).
  *
  * Stores the integer width value in `fmt->width`.
  *
  * @param format Format string pointer (will be advanced).
  * @param fmt Target format context.
  *
  * @see ft_atoi
  * @ingroup ft_printf
  */
 static void	parse_width(const char **format, t_fmt *fmt)
 {
	 fmt->width = ft_atoi(*format);
	 while (ft_isdigit(**format))
		 (*format)++;
 }
 
 /**
  * @brief Parses precision (e.g., `%.5d`).
  *
  * Precision is stored in `fmt->precision`. If the `.` is present but no
  * digits follow, precision is set to `0`.
  *
  * @param format Format string pointer (will be advanced).
  * @param fmt Target format context.
  *
  * @see ft_atoi
  * @ingroup ft_printf
  */
 static void	parse_precision(const char **format, t_fmt *fmt)
 {
	 if (**format == '.')
	 {
		 (*format)++;
		 if (ft_isdigit(**format))
		 {
			 fmt->precision = ft_atoi(*format);
			 while (ft_isdigit(**format))
				 (*format)++;
		 }
		 else
			 fmt->precision = 0;
	 }
 }
 
 /**
  * @brief Validates and stores the conversion specifier.
  *
  * Accepted specifiers: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`
  *
  * @param format Format string pointer (will be advanced).
  * @param fmt Target format context.
  * 
  * @return 0 if valid, -1 if unknown specifier.
  *
  * @see ft_strchr
  * @ingroup ft_printf
  */
 static int	parse_specifier(const char **format, t_fmt *fmt)
 {
	 if (**format == '\0')
		 return (-1);
	 if (ft_strchr("cspdiuxX%", **format))
	 {
		 fmt->specifier = **format;
		 (*format)++;
		 return (0);
	 }
	 fmt->specifier = '\0';
	 return (-1);
 }
 
 /**
  * @brief Parses a full format specification (flags, width, precision, specifier).
  *
  * @details
  * Parses from `%` until the final specifier character. Populates the given
  * `t_fmt` structure accordingly.
  *
  * @param format Format string pointer (will be advanced).
  * @param fmt Pointer to the format structure to populate.
  * 
  * @return 0 on success, -1 on invalid specifier.
  * 
  * @see parse_flags
  * @see parse_width
  * @see parse_precision
  * @see parse_specifier
  * @ingroup ft_printf
  */
 int	setup_format(const char **format, t_fmt *fmt)
 {
	 parse_flags(format, fmt);
	 parse_width(format, fmt);
	 parse_precision(format, fmt);
	 if (parse_specifier(format, fmt) == -1)
		 return (-1);
	 return (0);
 }
 