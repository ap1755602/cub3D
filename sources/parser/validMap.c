/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:11:56 by frodney           #+#    #+#             */
/*   Updated: 2021/11/29 17:28:55 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
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
			continue ;
		}
		else
			return (0);
	}
	free (str);
	str = NULL;
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
			lst->str[x] == 'E' || lst->str[x] == 'W' || lst->str[x] == '1')
			return ;
		else
			terminate("Error");
	}
}

static int	closeness_of_free_space(t_map_list *lst, int x)
{
	if (!lst)
		return (0);
	udlr(lst, x, UP);
	udlr(lst, x, DOWN);
	udlr(lst, x, LEFT);
	udlr(lst, x, RIGHT);
	return (1);
}

static void	valid_map_str(t_map_list *lst, t_map **map)
{
	int	i;

	i = 0;
	while (lst->str[i])
	{
		if (lst->str[i] == '0' && closeness_of_free_space(lst, i))
			i++;
		else if ((lst->str[i] == 'N' || lst->str[i] == 'S' || \
			lst->str[i] == 'E' || lst->str[i] == 'W') && !((*map)->player))
		{
			set_player_st(map, lst->str_num, i, lst->str[i]);
			closeness_of_free_space(lst, i);
			i++;
		}
		else if (lst->str[i] == '1' || lst->str[i] == ' ')
		{
			i++;
			continue ;
		}
		else
			terminate("Error");
	}
}

void	valid_map(t_map **map)
{
	t_map_list	*lst;

	if (!(*map)->lst || !(*map)->lst->next)
		terminate("Error");
	lst = (*map)->lst;
	while (lst->next)
	{
		valid_map_str(lst, map);
		lst = lst->next;
	}
	if (!(*map)->player)
		terminate("Error");
}
