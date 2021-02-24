
#include "utils.h"

void	padd_value(char *pad_char, int32_t padding, t_buffer *buffer)
{
	while (padding-- > 0)
		buffered_print(pad_char, 1, buffer);
}
