
#include "libft.h"

uintmax_t	ft_absl(intmax_t nb)
{
	intmax_t mask;

	mask = (nb >> (sizeof(nb) * CHAR_BIT - 1));
	nb = (uintmax_t)((nb + mask) ^ mask);
	return (nb);
}
