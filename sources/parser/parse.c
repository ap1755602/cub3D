/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:39:37 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 13:50:19 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_map	*parse(char *cub_file)
{
	t_format	*t;
	t_map		*map;
	char		*ptr;
	int			fd;

	t = init_st_texture();
	map = init_map_s();
	ptr = ft_strchr(cub_file, '.');
	ptr++;
	if (ft_strncmp(ptr, "cub\0", 4))
		terminate("Error");
	fd = open(cub_file, O_RDONLY, 0);
	if (!fd || read(fd, NULL, 0) < 0)
		terminate("Error");
	parse_format(fd, &t);
	parse_map(fd, &map);
	map->format = t;
	return (map);
}
