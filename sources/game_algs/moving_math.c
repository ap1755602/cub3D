/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:48:30 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/28 16:52:36 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	turn_left(t_coords *c)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = c->dirX;
	c->dirX = c->dirX * cos(ROT_SPEED) - c->dirY * sin(ROT_SPEED);
	c->dirY = old_dir_x * sin(ROT_SPEED) + c->dirY * cos(ROT_SPEED);
	old_plane_x = c->planeX;
	c->planeX = c->planeX * cos(ROT_SPEED) - c->planeY * sin(ROT_SPEED);
	c->planeY = old_plane_x * sin(ROT_SPEED) + c->planeY * cos(ROT_SPEED);
}

void	turn_right(t_coords *c)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = c->dirX;
	c->dirX = c->dirX * cos(-ROT_SPEED) - c->dirY * sin(-ROT_SPEED);
	c->dirY = old_dir_x * sin(-ROT_SPEED) + c->dirY * cos(-ROT_SPEED);
	old_plane_x = c->planeX;
	c->planeX = c->planeX * cos(-ROT_SPEED) - c->planeY * sin(-ROT_SPEED);
	c->planeY = old_plane_x * sin(-ROT_SPEED) + c->planeY * cos(-ROT_SPEED);
}

void	go_forward(t_coords *c, char **map)
{
	if (map[(int)c->posY][(int)(c->posX + c->dirX)] == '0')
		c->posX += MOVE_SPEED * c->dirX;
	if (map[(int)(c->posY + c->dirY)][(int)c->posX] == '0')
		c->posY += MOVE_SPEED * c->dirY;
}

void	go_backward(t_coords *c, char **map)
{
	if (map[(int)c->posY][(int)(c->posX - c->dirX)] == '0')
		c->posX -= MOVE_SPEED * c->dirX;
	if (map[(int)(c->posY - c->dirY)][(int)c->posX] == '0')
		c->posY -= MOVE_SPEED * c->dirY;
}
