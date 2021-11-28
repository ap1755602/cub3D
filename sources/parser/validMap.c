/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:39:42 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 13:39:43 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int	white_spaces_check(char *str)
{
	if (!ft_strncmp(str, "\0", 1))
		return (1);
	while (*str)
	{
		if (*str == ' ')
		{
			str++;
			continue;
		}
		else
			return (0);
	}
	return (1);
}

static void	udlr(t_map_list *lst, int x, int dir)
{
	while (x)
	{
		if (!lst || (size_t)x > ft_strlen(lst->str) || x < 0)
			terminate("Error");
		if (lst->str[x] == '0')
		{
			if (dir == UP)
				lst = lst->prev;
			else if (dir == DOWN)
				lst = lst->next;
			else if (dir == LEFT)
				x--;
			else if (dir == RIGHT)
				x++;
		}
		else if (lst->str[x] == 'N' || lst->str[x] == 'S' || \
			lst->str[x] == 'E' || lst->str[x] == 'W' ||  lst->str[x] == '1')
			return ;
		else
			terminate("Error");
	}
}

static int  closenessOfFreeSpace(t_map_list *lst, int x) // туда сюда попрыгать
{
	if(!lst)
		return (0);
	udlr(lst, x, UP);
	udlr(lst, x, DOWN);
	udlr(lst, x, LEFT);
	udlr(lst, x, RIGHT);
	return (1);
}

static void	setPlayerSt(t_map **map, int y, int x, char dir)
{
	(*map)->player = (t_player *)malloc(sizeof (t_player));
	(*map)->player->direction = dir;
	(*map)->player->x = x;
	(*map)->player->y = y;
}

void f(t_map_list *lst, t_map **map)
{
	int i;

	i = 0;
	while (lst->str[i])
	{
		if (lst->str[i] == '0' && closenessOfFreeSpace(lst, i))
			i++;
		else if ((lst->str[i] == 'N' || lst->str[i] == 'S' || \
			lst->str[i] == 'E' || lst->str[i] == 'W') && !((*map)->player))
		{
			setPlayerSt(map, lst->strNum, i, lst->str[i]);
			closenessOfFreeSpace(lst, i);
			i++;
		}
		else if (lst->str[i] == '1' || lst->str[i] == ' ')
		{
			i++;
			continue;
		}
		else
			terminate("Error");
	}
}

void validMap(t_map **map)
{
	t_map_list	*lst;

	if (!(*map)->lst || !(*map)->lst->next)
		terminate("Error");
	lst = (*map)->lst;
	while (lst->next)
	{
		f(lst, map);
		lst = lst->next;
	}
	if (!(*map)->player)
		terminate("Error");
}