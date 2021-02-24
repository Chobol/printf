
#include "libft.h"

void	*ft_realloc(void *ptr, size_t len, size_t new_len)
{
	void	*tmp;

	if (new_len == 0 || new_len <= len)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		if ((ptr = malloc(new_len)) == NULL)
			return (NULL);
		return (ptr);
	}
	if ((tmp = malloc(new_len)) == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(tmp, ptr, len);
	ft_bzero(tmp + len, new_len - len);
	free(ptr);
	return (tmp);
}
