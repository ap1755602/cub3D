/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:35:05 by frodney           #+#    #+#             */
/*   Updated: 2021/04/28 20:35:07 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*i;

	i = (t_list *)malloc(sizeof (t_list));
	if (!i)
		return (NULL);
	i->content = content;
	i->next = NULL;
	return (i);
}
