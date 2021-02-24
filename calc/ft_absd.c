
#include "libft.h"

double	ft_absd(double x)
{
	uint64_t casted;

	casted = *(uint64_t*)&x;
	casted &= 0x7FFFFFFFFFFFFFFF;
	return (*(double*)&casted);
}
