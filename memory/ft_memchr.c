
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bytes_s;

	bytes_s = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (bytes_s[i] == (unsigned char)c)
			return (&bytes_s[i]);
	return (NULL);
}
