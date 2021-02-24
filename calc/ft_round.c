
#include "libft.h"

intmax_t	ft_round(long double f)
{
	intmax_t	integer;
	long double	decimal;

	integer = (intmax_t)f;
	decimal = f - integer;
	if (f >= 0)
		return ((decimal < 0.5) ? integer : integer + 1);
	else
		return ((decimal > 0.5) ? integer : integer - 1);
}
