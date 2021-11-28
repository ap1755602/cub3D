/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:09:23 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 14:10:02 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*init_map_s(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->player = NULL;
	map->lst = NULL;
	return (map);
}

void	set_lst_map(int fd, t_map **map, char *str)
{
	char		*curr_str;
	t_map_list	*new;
	int			str_num;

	str_num = 1;
	new = lst_new(str, 0);
	lstadd_back(&(*map)->lst, new);
	while (get_next_line(fd, &curr_str))
	{
		if (white_spaces_check(curr_str))
			break ;
		else
		{
			new = lst_new(curr_str, str_num);
			lstadd_back(&(*map)->lst, new);
			str_num++;
		}
	}
	if (curr_str)
	{
		new = lst_new(curr_str, str_num);
		lstadd_back(&(*map)->lst, new);
	}
}

static void	create_2d_matrix(t_map **map)
{
	t_map_list	*last;
	t_map_list	*lst;

	last = lst_last((*map)->lst);
	lst = (*map)->lst;
	(*map)->m = (char **) malloc(sizeof (char *) * (last->str_num + 2));
	while (lst)
	{
		(*map)->m[lst->str_num] = ft_strdup(lst->str);
		lst = lst->next;
	}
	(*map)->m[last->str_num + 1] = NULL;
}

void	parse_map(int fd, t_map **map)
{
	char	*curr_str;

	while (get_next_line(fd, &curr_str))
	{
		if (white_spaces_check(curr_str))
			continue ;
		else
			break ;
	}
	set_lst_map(fd, map, curr_str);
	valid_map(map);
	create_2d_matrix(map);
}
