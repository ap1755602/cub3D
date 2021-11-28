#include "cub3D.h"

t_map_list	*lst_last(t_map_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	lstadd_back(t_map_list **lst, t_map_list *new)
{
	t_map_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->head = new;
		return ;
	}
	new->head = *lst;
	temp = lst_last((*lst)->head);
	temp->next = new;
	new->prev = temp;
}

t_map_list	*lst_new(char *str, int strNum)
{
	t_map_list	*i;

	i = (t_map_list *)malloc(sizeof (t_map_list));
	if (!i)
		return (NULL);
	i->str = str;
	i->strNum = strNum;
	i->next = NULL;
	i->prev = NULL;
	return (i);
}