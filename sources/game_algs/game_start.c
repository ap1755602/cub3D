#include "rendering.h"

void	game_init(t_game *game)
{
	game->wndw_size.x = 1280;
	game->wndw_size.y = 1024;
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

void	start_game(t_game *game)
{
	// double dirX = -1, dirY = 0; //initial direction vector
	// double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	// double time = 0; //time of current frame
	// double oldTime = 0; //time of previous frame
	game->coords.posX = game->map->player->x + 0.5;
	game->coords.posY = game->map->player->y + 0.5;
	game->coords.dirX = -1;
	game->coords.dirY = 0;
	game->coords.planeX = 0;
	game->coords.planeY = 0.66;
	game->flags.a_key = 0;
	game->flags.d_key = 0;
	game->flags.s_key = 0;
	game->flags.w_key = 0;
	game_init(game);
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_hook(game->window, 2, 0, ft_input, game);
	mlx_hook(game->window, 3, 0, key_unpress, game);
	// mlx_hook(game->window, 2, 0, ft_update, game);
	mlx_loop_hook(game->mlx, ft_update, game);
	mlx_loop(game->mlx);
}