#include "cub3D.h"
#include "rendering.h"

int main (int argc, char*argv[])
{
	t_game	game;

	if (argc == 2)
	{
		game.map = parse(argv[1]);
		start_game(&game);
		return (0);
	}
	terminate("Error");
}
