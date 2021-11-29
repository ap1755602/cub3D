/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:48:30 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/29 17:28:33 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	turn_left(t_coords *c)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = c->dirx;
	c->dirx = c->dirx * cos(ROT_SPEED) - c->diry * sin(ROT_SPEED);
	c->diry = old_dir_x * sin(ROT_SPEED) + c->diry * cos(ROT_SPEED);
	old_plane_x = c->planex;
	c->planex = c->planex * cos(ROT_SPEED) - c->planey * sin(ROT_SPEED);
	c->planey = old_plane_x * sin(ROT_SPEED) + c->planey * cos(ROT_SPEED);
}

void	turn_right(t_coords *c)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = c->dirx;
	c->dirx = c->dirx * cos(-ROT_SPEED) - c->diry * sin(-ROT_SPEED);
	c->diry = old_dir_x * sin(-ROT_SPEED) + c->diry * cos(-ROT_SPEED);
	old_plane_x = c->planex;
	c->planex = c->planex * cos(-ROT_SPEED) - c->planey * sin(-ROT_SPEED);
	c->planey = old_plane_x * sin(-ROT_SPEED) + c->planey * cos(-ROT_SPEED);
}

void	go_forward(t_coords *c, char **map)
{
	if (map[(int)c->posy][(int)(c->posx + c->dirx)] == '0')
		c->posx += MOVE_SPEED * c->dirx;
	if (map[(int)(c->posy + c->diry)][(int)c->posx] == '0')
		c->posy += MOVE_SPEED * c->diry;
}

void	go_backward(t_coords *c, char **map)
{
	if (map[(int)c->posy][(int)(c->posx - c->dirx)] == '0')
		c->posx -= MOVE_SPEED * c->dirx;
	if (map[(int)(c->posy - c->diry)][(int)c->posx] == '0')
		c->posy -= MOVE_SPEED * c->diry;
}
