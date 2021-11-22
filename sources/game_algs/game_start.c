#include "rendering.h"

void	game_init(t_game *game)
{
	game->wndw_size.x = 1200;
	game->wndw_size.y = 640;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x / 2 - 20,
			game->wndw_size.y,
			"iceCube3D");
	mlx_hook(game->window, 17, 0, exit_game, (void *)game);
}

void	start_game(t_game *game)
{
	game_init(game);
	mlx_hook(game->window, 2, 0, ft_input, (void *)&game);
	mlx_loop_hook(game->mlx, ft_update, (void *)&game);
	mlx_loop(game->mlx);
}