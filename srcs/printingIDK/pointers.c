
#include "printing.h"

int32_t	print_pointer(t_format format, va_list *app, t_buffer *buffer)
{
	void		*ptr;
	t_unsigned	nb;

	ptr = va_arg(*app, void *);
	nb.nb = (uintmax_t)ptr;
	nb.base = 16;
	nb.prefix = "0x";
	format.flags |= POINTER;
	format.flags |= PREFIX;
	print_unsigned(nb, format, buffer);
	return (SUCCESS);
}
