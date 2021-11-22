#include "rendering.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void 	drawing_square(t_game *game, int x, int y)
{
	int	width;
	int height;
	int tmp = x;
	width = x + 10;
	height = y + 10;
	while (y++ < height)
	{
		x = tmp;
		while (x++ < width)
		{
			my_mlx_pixel_put(&game->img, x, y, 0x00808080);
		}
	}
}

void	drawing_map(t_game *game, t_map *map)
{
	char **m;
	int	x;
	int	y;
//	int x1;
//	int y1;

	x = 0;
	y = 0;
	m = map->m;

//	x1 = 10;
//	y1 = 10;
	//=========print_map=============
//	int i = -1;
//	while ((map)->m[++i])
//		printf("%s\n", (map)->m[i]);

	game->img.img = mlx_new_image(game->mlx, 1280, 1024);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
									   &game->img.line_length, &game->img.endian);
	while (*m)
	{
		x = 0;
		while (**m)
		{
			if (**m == '1'){
				drawing_square(game, x, y);
			}
			(*m)++;
			x += 10;
		}
		m++;
		y += 10;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
}

void	game_init(t_game *game, t_map *map)
{
	game->wndw_size.x = 1280;
	game->wndw_size.y = 1024;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->wndw_size.x,
			game->wndw_size.y,
			"iceCube3D");
	drawing_map(game, map);
	mlx_hook(game->window, 17, 0, exit_game, (void *)game);
}

// отрисовать 2д карту

void	start_game(t_game *game, t_map *map)
{
	// double posX = 22, posY = 12;  //x and y start position
	// double dirX = -1, dirY = 0; //initial direction vector
	// double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	// double time = 0; //time of current frame
	// double oldTime = 0; //time of previous frame
	game_init(game, map);

	mlx_hook(game->window, 2, 0, ft_input, (void *)&game);
	mlx_loop_hook(game->mlx, ft_update, (void *)&game);
	mlx_loop(game->mlx);
}