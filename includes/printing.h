
#ifndef PRINTING_H
# define PRINTING_H

# include "ft_printf.h"
# include "parsing.h"
# include "utils.h"

# define NB_STR_MAX (size_t)21
# define PAD_RIGHT	(uint8_t)1
# define PAD_LEFT	(uint8_t)0

# define D_PREFIX		""
# define B_PREFIX		"0b"
# define O_PREFIX		"0"
# define X_PREFIX		"0x"
# define XUP_PREFIX		"0X"

void	buffered_print(void *data, size_t size, t_buffer *buffer);
void	buffer_wchar(wchar_t wchar, t_buffer *buffer);
void	buffer_wstring(wchar_t *wstr, int64_t len, t_buffer *buffer);
int32_t	print_arg(t_format format, va_list *app, t_buffer *buffer);
int32_t	print_base(t_format format, va_list *app, t_buffer *buffer);
int32_t	print_bytes(t_format format, va_list *app, t_buffer *buffer);
int32_t	print_char(t_format format, va_list *app, t_buffer *buffer);
int32_t	print_integer(t_format format, va_list *app, t_buffer *buffer);
int32_t	print_floats(t_format format, va_list *app, t_buffer *buffer);
void	print_float_number(t_double nb, t_format format, t_buffer *buffer);
void	print_float_scientific(t_double nb, t_format format, t_buffer *buffer);
void	print_float_shorter(t_double nb, t_format format, t_buffer *buffer);
void	print_signed(intmax_t nb, t_format format, t_buffer *buffer);
int32_t	print_percent(t_format format, va_list *app, t_buffer *buffer);
int32_t	print_pointer(t_format format, va_list *app, t_buffer *buffer);
int32_t	print_string(t_format format, va_list *app, t_buffer *buffer);
void	print_unsigned(t_unsigned nb, t_format format, t_buffer *buffer);

#endif
