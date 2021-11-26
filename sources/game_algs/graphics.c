#include "rendering.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
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

void	draw_player(t_game *game)
{
	drawing_square(game, game->map->player->x * 10, game->map->player->y * 10);
}

int	drawing_map(t_game *game)
{
	char **m;
	int	x;
	int	y;
	int i = 0;
	int j = 0;
	x = 0;
	y = 0;
	m = game->map->m;
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	while (m[i])
	{
		x = 0;
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == '1'){
				drawing_square(game, x, y);
			}
			j++;
			x += 10;
		}
		i++;
		y += 10;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return(0);
}

void	draw_line(t_img *img, int x, int startDraw, int endDraw, int color)
{
	int y = startDraw;
	while (y < endDraw)
	{
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

void	graphics(t_game *game)
{
	int x = 0;
	while (x < game->wndw_size.x)
	{
			//calculate ray position and direction
		double cameraX = 2 * x / (double)game->wndw_size.x - 1; //x-coordinate in camera space
		double rayDirX = game->coords.dirX + game->coords.planeX * cameraX;
		double rayDirY = game->coords.dirY + game->coords.planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)(game->coords.posX);
		int mapY = (int)(game->coords.posY);

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);

		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->coords.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->coords.posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->coords.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->coords.posY) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
			}
			else
			{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
			}
			//Check if ray has hit a wall
			if(game->map->m[mapY][mapX] != '0') hit = 1;
		}

		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(game->wndw_size.y / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + game->wndw_size.y / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + game->wndw_size.y / 2;
		if(drawEnd >= game->wndw_size.y) drawEnd = game->wndw_size.y - 1;
		draw_line(&game->img, x, drawStart, drawEnd, 0x00808080);
		draw_line(&game->img, x, 0, drawStart, 0x0033b5ff);
		draw_line(&game->img, x, drawEnd, game->wndw_size.y - 1, 0x00ebe7ea);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
}

int	ft_update(t_game *game)
{
	graphics(game);
	// (void )game; 
	mlx_do_sync(game->mlx);
	return (1);
}
