/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:50:16 by frodney           #+#    #+#             */
/*   Updated: 2021/11/29 17:43:23 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
** Including of headers:
*/

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include <stdbool.h>

/*
** Gameplay define:
*/

# define MOVE_SPEED 0.2
# define ROT_SPEED 0.09
# define TEXWIDTH 64
# define TEXHEIGHT 64

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
** ########################################################################
** ########################## CONFIG PARSING ##############################
** ########################################################################
** ######################### Folder: parsing ##############################
** ########################################################################
*/

/*
** File: initPlayerSt.c
*/

void		set_player_st(t_map **map, int y, int x, char dir);

/*
** File: lst.c
*/

t_map_list	*lst_new(char *str, int str_num);
t_map_list	*lst_last(t_map_list *lst);
void		lstadd_back(t_map_list **lst, t_map_list *new);

/*
** File: parse.c
*/

t_map		*parse(char *cubFile);

/*
** File: parseColors.c
*/

void		set_value_f_c(char *str, int *i);

/*
** File: parseMap.c
*/

t_map		*init_map_s(void);
void		parse_map(int fd, t_map **map);

/*
** File: parseTextures.c
*/

t_format	*init_st_texture(void);
void		parse_format(int fd, t_format **t);

/*
** File: validMap.c
*/

void		valid_map(t_map **map);
int			white_spaces_check(char *str);

#endif