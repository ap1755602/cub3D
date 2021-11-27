#include "rendering.h"

void	game_init(t_game *game)
{
	game->wndw_size.x = 640;
	game->wndw_size.y = 480;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x,
			game->wndw_size.y,
			"iceCube3D");
	game->img.img = mlx_new_image(game->mlx, game->wndw_size.x, game->wndw_size.y);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
									   &game->img.line_length, &game->img.endian);
}

int key_unpress(int key, t_game *game)
{
	if (key == KEY_UP)
		game->flags.w_key = 0;
	if (key == KEY_DOWN)
		game->flags.s_key = 0;
	if (key == KEY_LEFT)
		game->flags.a_key = 0;
	if (key == KEY_RIGHT)
		game->flags.d_key = 0;
	if (key == ESC)
		exit_game(game);
	else
		return (0);
	return (1);
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
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->size.x, &tex->size.y);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line, &tex->endian);
}

void	start_game(t_game *game)
{
	game->coords.posX = game->map->player->x + 0.5;
	game->coords.posY = game->map->player->y + 0.5;
	game->flags.a_key = 0;
	game->flags.d_key = 0;
	game->flags.s_key = 0;
	game->flags.w_key = 0;
	plane_init(&game->coords, game->map->player);
	dir_init(&game->coords, game->map->player);
	game->texs = malloc(4 * sizeof(t_texture));
	// init_texture(game, &game->texs[0], "./imgs/brick1.xpm");
	game_init(game);
	// game->texs[0].img = mlx_xpm_file_to_image(game->mlx, "./imgs/brick1.xpm", &game->texs[0].size.x, &game->texs[0].size.y);
	// game->texs[0].addr = mlx_get_data_addr(game->texs[0].img, &game->texs[0].bpp, &game->texs[0].size_line, &game->texs[0].endian);
	init_texture(game, &game->texs[0], "./imgs/brick1.xpm");
	init_texture(game, &game->texs[1], "./imgs/brick2.xpm");
	init_texture(game, &game->texs[2], "./imgs/brick3.xpm");
	init_texture(game, &game->texs[3], "./imgs/brick4.xpm");
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, 0, key_press, game);
	mlx_hook(game->window, 3, 0, key_unpress, game);
	// mlx_hook(game->window, 2, 0, ft_update, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_loop(game->mlx);
}