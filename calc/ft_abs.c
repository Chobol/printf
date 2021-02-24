
#include "libft.h"

uint32_t	ft_abs(int32_t nb)
{
	int32_t mask;

	mask = (nb >> (sizeof(int32_t) * CHAR_BIT - 1));
	nb = (uint32_t)((nb + mask) ^ mask);
	return (nb);
}
