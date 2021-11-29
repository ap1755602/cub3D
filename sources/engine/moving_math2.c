/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_math2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:47:57 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/29 17:28:33 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	go_left(t_coords *c, char **map)
{
	if (map[(int)c->posy][(int)(c->posx - c->planex)] == '0')
		c->posx -= MOVE_SPEED * c->planex;
	if (map[(int)(c->posy - c->planey)][(int)c->posx] == '0')
		c->posy -= MOVE_SPEED * c->planey;
}

void	go_right(t_coords *c, char **map)
{
	if (map[(int)c->posy][(int)(c->posx + c->planex)] == '0')
		c->posx += MOVE_SPEED * c->planex;
	if (map[(int)(c->posy + c->planey)][(int)c->posx] == '0')
		c->posy += MOVE_SPEED * c->planey;
}
