#include "libft.h"

// klll;,;.m
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(lst[0]);
	temp->next = new;
}