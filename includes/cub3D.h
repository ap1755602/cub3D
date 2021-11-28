/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:50:16 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 16:52:36 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>

# define MOVE_SPEED 0.2
# define ROT_SPEED 0.09

typedef struct s_format
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
}	t_format;

typedef struct s_map_list
{
	int					str_num;
	char				*str;
	struct s_map_list	*head;
	struct s_map_list	*next;
	struct s_map_list	*prev;
}	t_map_list;

typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
}	t_player;

typedef struct s_map
{
	t_player		*player;
	t_map_list		*lst;
	t_format		*format;
	char			**m;
}	t_map;

/*
 * parse functions
 */

t_map		*init_map_s(void);
t_map_list	*lst_new(char *str, int str_num);
void		lstadd_back(t_map_list **lst, t_map_list *new);
t_map_list	*lst_last(t_map_list *lst);
void		parse_map(int fd, t_map **map);
void		valid_map(t_map **map);
t_map		*parse(char *cubFile);
t_format	*init_st_texture(void);
void		parse_format(int fd, t_format **t);
int			white_spaces_check(char *str);
void		set_value_f_c(char *str, int *i);
void		set_player_st(t_map **map, int y, int x, char dir);

#endif