/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:39:40 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 13:39:41 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*initMapS(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map)); // free
	map->player = NULL;
	map->lst = NULL;
	return (map);
}


void	setLstMap(int fd, t_map **map, char *str)
{
	char		*currStr;
	t_map_list	*new;
	int 		strNum;

	strNum = 1;
	new = lst_new(str, 0);
	lstadd_back(&(*map)->lst, new);
	while(get_next_line(fd, &currStr))
	{
		if (white_spaces_check(currStr))
		{
			free (currStr);
			currStr = NULL;
			break;
		}
		else
		{
			new = lst_new(currStr, strNum);
			lstadd_back(&(*map)->lst, new);
			strNum++;
		}
	}
	if (currStr)
	{
		new = lst_new(currStr, strNum);
		lstadd_back(&(*map)->lst, new);
	}
}

static void	create2dMatrix(t_map **map)
{
	t_map_list	*last;
	t_map_list	*lst;


	last = lst_last((*map)->lst);
	lst = (*map)->lst;
	(*map)->m = (char **) malloc(sizeof (char *) * (last->strNum + 2));
	while (lst)
	{
		(*map)->m[lst->strNum] = ft_strdup(lst->str);
		lst = lst->next;
	}
	(*map)->m[last->strNum + 1] = NULL;
}

void parseMap(int fd, t_map **map)
{
	char	*currStr;

	while(get_next_line(fd, &currStr))
	{
		if (white_spaces_check(currStr))
		{
			free(currStr);
			continue;
		}
		else
			break;
	}
	setLstMap(fd, map, currStr);
	validMap(map);
	create2dMatrix(map);
	//--------print_2d_matrix-------
	// int i = -1;
	// while ((*map)->m[++i])
	// 	printf("%s\n", (*map)->m[i]);

}