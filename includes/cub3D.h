/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:50:16 by frodney           #+#    #+#             */
/*   Updated: 2021/11/27 13:43:38 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>

#define MOVE_SPEED 0.2
#define ROTATE_SPEED 0.09

typedef struct s_format
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
}	t_format;

typedef struct s_map_list
{
	int					strNum;
	char				*str;
	struct s_map_list	*head;
	struct s_map_list	*next;
	struct s_map_list	*prev;
}	t_map_list;

typedef struct s_player
{
	int		x;
	int 	y;
	char 	direction;
}	t_player;

typedef struct s_map
{
	t_player		*player;
	t_map_list		*lst;
	t_format		*format;
	char	**m;
}	t_map;

/*
 * parse functions
 */

t_map		*initMapS(void);
t_map_list	*lst_new(char *str, int strNum);
void		lstadd_back(t_map_list **lst, t_map_list *new);
t_map_list	*lst_last(t_map_list *lst);
void		parseMap(int fd, t_map **map);
void		validMap(t_map **map);
t_map		*parse(char *cubFile);
t_format	*initStT(void);
void		parseFormat(int fd, t_format **t);
int			white_spaces_check(char *str);

#endif