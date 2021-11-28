/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:47:57 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/28 16:47:58 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	go_left(t_coords *c, char **map)
{
	if (map[(int)c->posY][(int)(c->posX - c->planeX)] == '0')
		c->posX -= MOVE_SPEED * c->planeX;
	if (map[(int)(c->posY - c->planeY)][(int)c->posX] == '0')
		c->posY -= MOVE_SPEED * c->planeY;
}

void	go_right(t_coords *c, char **map)
{
	if (map[(int)c->posY][(int)(c->posX + c->planeX)] == '0')
		c->posX += MOVE_SPEED * c->planeX;
	if (map[(int)(c->posY + c->planeY)][(int)c->posX] == '0')
		c->posY += MOVE_SPEED * c->planeY;
}
