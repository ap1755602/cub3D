#include "rendering.h"

int	ft_input(int key, t_game *game)
{
	if (key == KEY_UP)
		game->map->player->y--;
	if (key == KEY_DOWN)
		game->map->player->y++;
	if (key == KEY_LEFT)
		game->map->player->x--;
	if (key == KEY_RIGHT)
		game->map->player->x++;
	if (key == ESC)
		exit_game(game);
	else
		return (0);
	return (1);
}