
#include "libft.h"


long double	ft_absld(long double x)
{
	uintmax_t	casted;

	if (sizeof(long double) == 8)
	{
		casted = *(uintmax_t*)&x;
		casted &= 0x7FFFFFFFFFFFFFFF;
		return (*(long double*)&casted);
	}
	else
		return ((x < 0) ? -x : x);
}
