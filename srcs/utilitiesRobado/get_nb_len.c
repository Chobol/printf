
#include "utils.h"

size_t	get_nb_len(uintmax_t nb, uint8_t base)
{
	size_t	nb_len;

	if (nb == 0)
		return (1);
	nb_len = 0;
	while (nb > 0)
	{
		nb /= base;
		nb_len++;
	}
	return (nb_len);
}
