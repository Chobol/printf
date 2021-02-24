
#include "printing.h"

int32_t	print_bytes(t_format format, va_list *app, t_buffer *buffer)
{
	format = (t_format)format;
	*va_arg(*app, int *) = buffer->bytes_written;
	return (SUCCESS);
}
