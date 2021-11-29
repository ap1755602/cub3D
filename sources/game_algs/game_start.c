/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:02:43 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/29 12:00:24 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	game_init(t_game *game, t_img *img)
{
	game->wndw_size.x = 640;
	game->wndw_size.y = 480;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x,
			game->wndw_size.y,
			"iceCube3D");
	img->img = mlx_new_image(game->mlx, game->wndw_size.x, game->wndw_size.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	game->flags.a_key = 0;
	game->flags.d_key = 0;
	game->flags.s_key = 0;
	game->flags.w_key = 0;
	game->flags.left_key = 0;
	game->flags.right_key = 0;
}

void	dir_init(t_coords *c, t_player *p)
{
	if (p->direction == 'W')
	{
		c->dirX = -1;
		c->dirY = 0;
	}
	if (p->direction == 'E')
	{
		c->dirX = 1;
		c->dirY = 0;
	}
	if (p->direction == 'N')
	{
		c->dirX = 0;
		c->dirY = 1;
	}
	if (p->direction == 'S')
	{
		c->dirX = 0;
		c->dirY = -1;
	}
}

void	plane_init(t_coords *c, t_player *p)
{
	if (p->direction == 'W')
	{
		c->planeX = 0;
		c->planeY = 0.66;
	}
	if (p->direction == 'E')
	{
		c->planeX = 0;
		c->planeY = -0.66;
	}
	if (p->direction == 'N')
	{
		c->planeX = 0.66;
		c->planeY = 0;
	}
	if (p->direction == 'S')
	{
		c->planeX = -0.66;
		c->planeY = 0;
	}
}

void	init_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->size.x,
			&tex->size.y);
	if (!tex->img)
	{
		free(game->texs);
		terminate("Error: Image doesn't exist");
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line,
			&tex->endian);
}

void	start_game(t_game *game)
{
	game->coords.posX = game->map->player->x + 0.5;
	game->coords.posY = game->map->player->y + 0.5;
	plane_init(&game->coords, game->map->player);
	dir_init(&game->coords, game->map->player);
	game->texs = malloc(4 * sizeof(t_texture));
	game_init(game, &game->img);
	init_texture(game, &game->texs[0], game->map->format->ea);
	init_texture(game, &game->texs[1], game->map->format->we);
	init_texture(game, &game->texs[2], game->map->format->no);
	init_texture(game, &game->texs[3], game->map->format->so);
	game->map->m[game->map->player->y][game->map->player->x] = '0';
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, 0, key_press, game);
	mlx_hook(game->window, 3, 0, key_unpress, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_loop(game->mlx);
}
