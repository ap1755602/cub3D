/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initPlayerSt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:48:23 by frodney           #+#    #+#             */
/*   Updated: 2021/11/29 17:28:55 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_player_st(t_map **map, int y, int x, char dir)
{
	(*map)->player = (t_player *)malloc(sizeof (t_player));
	(*map)->player->direction = dir;
	(*map)->player->x = x;
	(*map)->player->y = y;
}
