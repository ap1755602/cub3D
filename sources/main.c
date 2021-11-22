#include "cub3D.h"
#include "rendering.h"

int main (int argc, char*argv[])
{
	t_game	game;
	t_map	*map;

	if (argc == 2)
	{
		map = parse(argv[1]);
		start_game(&game, map);
		return (0);
	}
	terminate("Error");
}