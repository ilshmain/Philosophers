#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;

	if (!lst)
		return ;
	while (*lst)
	{
		new = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = new;
	}
}
