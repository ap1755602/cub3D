/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:30:36 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/29 17:28:33 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	step_and_side_dist_calcs(t_game *game, t_dataRay *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (game->coords.posx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - game->coords.posx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (game->coords.posy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - game->coords.posy) * r->deltadisty;
	}
}

void	dda_algorithm(t_game *game, t_dataRay *r)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (game->map->m[r->mapy][r->mapx] != '0')
			r->hit = 1;
	}
	if (r->side == 0)
		r->perpwalldist = (r->sidedistx - r->deltadistx);
	else
		r->perpwalldist = (r->sidedisty - r->deltadisty);
}

void	lines_calcs(t_game *game, t_dataRay *r)
{
	r->lineheight = (int)(game->wndw_size.y / r->perpwalldist);
	r->drawstart = -r->lineheight / 2 + game->wndw_size.y / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + game->wndw_size.y / 2;
	if (r->drawend >= game->wndw_size.y)
		r->drawend = game->wndw_size.y - 1;
}

void	which_wall(t_game *game, t_dataRay *r)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = game->coords.posy + r->perpwalldist * r->raydiry;
	else
		wall_x = game->coords.posx + r->perpwalldist * r->raydirx;
	wall_x -= floor(wall_x);
	r->texx = (int)(wall_x * (double)(TEXWIDTH));
	if (r->side == 0 && r->raydirx > 0)
		r->texx = TEXWIDTH - r->texx - 1;
	if (r->side == 1 && r->raydiry < 0)
		r->texx = TEXWIDTH - r->texx - 1;
	r->step = 1.0 * TEXHEIGHT / r->lineheight;
	r->texpos = (r->drawstart - game->wndw_size.y / 2 + r->lineheight / 2);
	r->texpos *= r->step;
}

void	assign_texture_pixels(t_game *game, t_dataRay *r, int x)
{
	unsigned int	color;
	int				y;

	y = r->drawstart;
	while (y < r->drawend)
	{
		r->texy = (int)r->texpos & (TEXHEIGHT - 1);
		r->texpos += r->step;
		if (r->side == 0)
		{
			if (r->stepx == 1)
				color = get_color(&game->texs[1], r->texx, r->texy);
			else
				color = get_color(&game->texs[0], r->texx, r->texy);
		}
		if (r->side == 1)
		{
			if (r->stepy == 1)
				color = get_color(&game->texs[3], r->texx, r->texy);
			else
				color = get_color(&game->texs[2], r->texx, r->texy);
		}
		apply_pixel(&game->img, x, y, color);
		y++;
	}
}
