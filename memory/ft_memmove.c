
#include "libft.h"


void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*byte_src;
	unsigned char	*byte_dst;
	size_t			overlap;
	size_t			i;

	byte_dst = (unsigned char *)dst;
	byte_src = (unsigned char *)src;
	overlap = -1;
	while (++overlap < len)
	{
		if (src + overlap == dst + len)
		{
			i = 0;
			while (i < len)
			{
				byte_dst[i] = byte_src[i];
				++i;
			}
			return ((void *)byte_dst);
		}
	}
	return (ft_memcpy(dst, src, len));
}
