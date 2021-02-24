

#include "libft.h"

uint32_t	ft_sqrt(uint32_t nb)
{
	uint32_t result;
	uint32_t mask;

	result = 0;
	mask = 1ul << 30;
	while (mask > nb)
		mask >>= 2;
	while (mask != 0)
	{
		if (nb >= result + mask)
		{
			nb = nb - (result + mask);
			result = result + (2 * mask);
		}
		result >>= 1;
		mask >>= 2;
	}
	if (nb > result)
		result++;
	return (result);
}
