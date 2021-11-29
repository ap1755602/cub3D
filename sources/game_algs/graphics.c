/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:30:36 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/29 11:59:04 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	step_and_side_dist_calcs(t_game *game, t_dataRay *r)
{
	if (r->rayDirX < 0)
	{
		r->stepX = -1;
		r->sideDistX = (game->coords.posX - r->mapX) * r->deltaDistX;
	}
	else
	{
		r->stepX = 1;
		r->sideDistX = (r->mapX + 1.0 - game->coords.posX) * r->deltaDistX;
	}
	if (r->rayDirY < 0)
	{
		r->stepY = -1;
		r->sideDistY = (game->coords.posY - r->mapY) * r->deltaDistY;
	}
	else
	{
		r->stepY = 1;
		r->sideDistY = (r->mapY + 1.0 - game->coords.posY) * r->deltaDistY;
	}
}

void	dda_algorithm(t_game *game, t_dataRay *r)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->sideDistX < r->sideDistY)
		{
			r->sideDistX += r->deltaDistX;
			r->mapX += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sideDistY += r->deltaDistY;
			r->mapY += r->stepY;
			r->side = 1;
		}
		if (game->map->m[r->mapY][r->mapX] != '0')
			r->hit = 1;
	}
	if (r->side == 0)
		r->perpWallDist = (r->sideDistX - r->deltaDistX);
	else
		r->perpWallDist = (r->sideDistY - r->deltaDistY);
}

void	lines_calcs(t_game *game, t_dataRay *r)
{
	r->lineHeight = (int)(game->wndw_size.y / r->perpWallDist);
	r->drawStart = -r->lineHeight / 2 + game->wndw_size.y / 2;
	if (r->drawStart < 0)
		r->drawStart = 0;
	r->drawEnd = r->lineHeight / 2 + game->wndw_size.y / 2;
	if (r->drawEnd >= game->wndw_size.y)
		r->drawEnd = game->wndw_size.y - 1;
}

void	which_wall(t_game *game, t_dataRay *r)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = game->coords.posY + r->perpWallDist * r->rayDirY;
	else
		wall_x = game->coords.posX + r->perpWallDist * r->rayDirX;
	wall_x -= floor(wall_x);
	r->texX = (int)(wall_x * (double)(texWidth));
	if (r->side == 0 && r->rayDirX > 0)
		r->texX = texWidth - r->texX - 1;
	if (r->side == 1 && r->rayDirY < 0)
		r->texX = texWidth - r->texX - 1;
	r->step = 1.0 * texHeight / r->lineHeight;
	r->texPos = (r->drawStart - game->wndw_size.y / 2 + r->lineHeight / 2);
	r->texPos *= r->step;
}

void	assign_texture_pixels(t_game *game, t_dataRay *r, int x)
{
	unsigned int	color;
	int				y;

	y = r->drawStart;
	while (y < r->drawEnd)
	{
		r->texY = (int)r->texPos & (texHeight - 1);
		r->texPos += r->step;
		if (r->side == 0)
		{
			if (r->stepX == 1)
				color = get_color(&game->texs[1], r->texX, r->texY);
			else
				color = get_color(&game->texs[0], r->texX, r->texY);
		}
		if (r->side == 1)
		{
			if (r->stepY == 1)
				color = get_color(&game->texs[2], r->texX, r->texY);
			else
				color = get_color(&game->texs[3], r->texX, r->texY);
		}
		apply_pixel(&game->img, x, y, color);
		y++;
	}
}
