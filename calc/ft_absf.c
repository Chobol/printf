
#include "libft.h"

float	ft_absf(float x)
{
	uint64_t casted;

	casted = *(uint64_t*)&x;
	casted &= 0x7FFFFFFF;
	return (*(float*)&casted);
}
