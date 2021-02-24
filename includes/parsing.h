
#ifndef FORMAT_PARSING_H
# define FORMAT_PARSING_H

# include "ft_printf.h"
# include "printing.h"
# include "utils.h"


# define RIGHT_PAD	(1 << 0)
# define SIGN		(1 << 1)
# define PREFIX		(1 << 2)
# define SPACE		(1 << 3)
# define ZERO_PAD	(1 << 4)

# define UPPER	(1 << 5)

# define SHORT		(1 << 7)
# define SSHORT		(1 << 8)
# define LONG		(1 << 9)
# define LLONG		(1 << 10)
# define INTMAX		(1 << 11)
# define SIZE_T		(1 << 12)
# define PTRDIFF	(1 << 13)
# define LDOUBLE	(1 << 14)

# define MIN_LEN	(1 << 15)
# define PRECISION	(1 << 16)
# define POINTER	(1 << 17)

void	get_specifier(char **string, t_format *format);
char	*parse_format(char *str, va_list *app, t_buffer *buffer);
int32_t	seek_flag(char **string, t_format *format);
int32_t	seek_length(char **string, t_format *format);
int32_t	seek_precision(char **string, t_format *format, va_list *app);
int32_t	seek_width(char **string, t_format *format, va_list *app);

#endif
