/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseTextures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:39:49 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 14:14:41 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_format	*init_st_texture(void)
{
	t_format	*t;

	t = (t_format *)malloc(sizeof (t_format));
	t->no = NULL;
	t->so = NULL;
	t->we = NULL;
	t->ea = NULL;
	t->f = -1;
	t->c = -1;
	return (t);
}

static void	check_file_format(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(&(str[i]), ".xpm\0", 5))
		terminate("Error");
}

static void	set_value_texture(char *str, char **value)
{
	char	*ptr;
	char	*trimed_path;

	if (*value)
		terminate("Error");
	ptr = ft_strchr(str, ' ');
	trimed_path = ft_strtrim(ptr, " ");
	if (!ptr || !trimed_path)
		terminate("Error");
	check_file_format(trimed_path);
	*value = trimed_path;
	free (str);
}

static void	set_format(char *str, t_format **t)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		set_value_texture(str, &(*t)->no);
	}
	else if (!ft_strncmp(str, "SO ", 3))
		set_value_texture(str, &(*t)->so);
	else if (!ft_strncmp(str, "WE ", 3))
		set_value_texture(str, &(*t)->we);
	else if (!ft_strncmp(str, "EA ", 3))
		set_value_texture(str, &(*t)->ea);
	else if (!ft_strncmp(str, "F ", 2))
		set_value_f_c(str, &(*t)->f);
	else if (!ft_strncmp(str, "C ", 2))
		set_value_f_c(str, &(*t)->c);
	else
		terminate("Error");
}

void	parse_format(int fd, t_format **t)
{
	int		counter;
	char	*curr_str;

	counter = 6;
	while (counter && get_next_line(fd, &curr_str))
	{
		if (!ft_strncmp(curr_str, "\0", 1))
		{
			free (curr_str);
			continue ;
		}
		counter--;
		set_format(curr_str, t);
	}
}
