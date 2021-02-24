
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == NULL)
		return ;
	if ((*alst)->content != NULL)
		del((*alst)->content, (*alst)->content_size);
	if (*alst != NULL)
		free(*alst);
	*alst = NULL;
}
