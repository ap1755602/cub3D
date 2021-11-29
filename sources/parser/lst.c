/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:39:31 by frodney           #+#    #+#             */
/*   Updated: 2021/11/29 17:28:55 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

t_map_list	*lst_new(char *str, int str_num)
{
	t_map_list	*i;

	i = (t_map_list *)malloc(sizeof (t_map_list));
	if (!i)
		return (NULL);
	i->str = str;
	i->str_num = str_num;
	i->next = NULL;
	i->prev = NULL;
	return (i);
}
