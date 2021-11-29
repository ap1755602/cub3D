/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:03:45 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/29 13:18:18 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	draw_ceil(t_game *game, int x, int endDraw, int color)
{
	int	y;

	y = 0;
	while (y < endDraw)
	{
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
}

void	draw_floor(t_game *game, int x, int startDraw, int color)
{
	int	y;

	y = startDraw;
	while (y < game->wndw_size.y - 1)
	{
		my_mlx_pixel_put(&game->img, x, y, color);
		y++;
	}
}

void	graphics(t_game *game)
{
	t_dataRay	r;
	int			x;

	x = 0;
	while (x < game->wndw_size.x)
	{
		ray_calcs(game, &r, x);
		step_and_side_dist_calcs(game, &r);
		dda_algorithm(game, &r);
		lines_calcs(game, &r);
		which_wall(game, &r);
		assign_texture_pixels(game, &r, x);
		draw_ceil(game, x, r.drawstart, game->map->format->c);
		draw_floor(game, x, r.drawend, game->map->format->f);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
}

int	ft_update(t_game *game)
{
	if (game->flags.w_key == 1)
		go_forward(&game->coords, game->map->m);
	if (game->flags.s_key == 1)
		go_backward(&game->coords, game->map->m);
	if (game->flags.d_key == 1)
		go_right(&game->coords, game->map->m);
	if (game->flags.a_key == 1)
		go_left(&game->coords, game->map->m);
	if (game->flags.left_key == 1)
		turn_left(&game->coords);
	if (game->flags.right_key == 1)
		turn_right(&game->coords);
	graphics(game);
	mlx_do_sync(game->mlx);
	return (1);
}
