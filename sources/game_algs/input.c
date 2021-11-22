#include "rendering.h"

int	ft_input(int key, t_game *game)
{
	if (key == ESC)
		exit_game(game);
	// if (game->player.cell == NULL)
		// return (0);
	else
		return (0);
	return (1);
}