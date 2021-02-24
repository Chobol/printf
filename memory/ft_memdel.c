

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap == NULL)
		return ;
	if (*ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}
