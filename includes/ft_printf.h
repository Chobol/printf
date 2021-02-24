
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include "libft.h"

# define SUCCESS				(int32_t)0
# define FAILURE				(int32_t)-1
# define UNDEFINED_BEHAVIOUR	(int8_t)-1
# define ITOA					(uint8_t)33
# define X64_SIZE				(size_t)64

typedef struct	s_format
{
	uint32_t	flags;
	int32_t		width;
	int32_t		precision;
	int32_t		to_print;
	char		specifier;
}				t_format;

typedef struct	s_buffer
{
	char		buffer[X64_SIZE] __attribute__((__aligned__(8)));
	size_t		buffer_index;
	uintmax_t	bytes_written;
	int8_t		undefined_behaviour;
}				t_buffer;

typedef struct	s_functions
{
	int32_t		(*ptrfunc)(t_format, va_list*, t_buffer*);
	char		specifier;
}				t_functions;

typedef struct	s_unsigned
{
	uintmax_t	nb;
	uint8_t		base;
	char		*prefix;
}				t_unsigned;

typedef struct	s_double
{
	long double	nb;
	uint8_t		base;
	char		*prefix;
}				t_double;

int				ft_printf(const char *format, ...);

#endif
