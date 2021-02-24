

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	t_byte	*memory;

	if ((memory = malloc(sizeof(memory) * size)) == NULL)
		return (NULL);
	ft_memset((void *)memory, 0, size);
	return ((void *)memory);
}
