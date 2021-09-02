#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_struct;

	new_struct = (t_list *)malloc(sizeof(t_list));
	if (!new_struct)
		return (NULL);
	new_struct->content = content;
	new_struct->next = NULL;
	return (new_struct);
}

typedef struct s_list
{
	void			*content;
	struct s_list	*next;	
}				t_list;