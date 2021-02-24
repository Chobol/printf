
#include "printing.h"

int32_t	print_percent(t_format format, va_list *app, t_buffer *buffer)
{
	int32_t	width;

	app = (va_list*)app;
	format = (t_format)format;
	width = (format.width > 0) ? format.width - 1 : 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", width, buffer);
	buffer_wchar('%', buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
	return (SUCCESS);
}
