#include "rendering.h"

void	turn_left(t_coords *c)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = c->dirX;
	c->dirX = c->dirX * cos(0.05) - c->dirY * sin(0.05);
	c->dirY = oldDirX * sin(0.05) + c->dirY * cos(0.05);
	oldPlaneX = c->planeX;
	c->planeX = c->planeX * cos(0.05) - c->planeY * sin(0.05);
	c->planeY = oldPlaneX * sin(0.05) + c->planeY * cos(0.05);
}

void	turn_right(t_coords *c)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = c->dirX;
	c->dirX = c->dirX * cos(-0.05) - c->dirY * sin(-0.05);
	c->dirY = oldDirX * sin(-0.05) + c->dirY * cos(-0.05);
	oldPlaneX = c->planeX;
	c->planeX = c->planeX * cos(-0.05) - c->planeY * sin(-0.05);
	c->planeY = oldPlaneX * sin(-0.05) + c->planeY * cos(-0.05);
}

void	go_forward(t_coords *c, char **map)
{
	if (map[(int)c->posY][(int)(c->posX + c->dirX)] == '0')
		c->posX += 0.3 * c->dirX;
	if (map[(int)(c->posY + c->dirY)][(int)c->posX] == '0')
		c->posY += 0.3 * c->dirY;
}

void	go_backward(t_coords *c, char **map)
{
	if (map[(int)c->posY][(int)(c->posX - c->dirX)] == '0')
		c->posX -= 0.3 * c->dirX;
	if (map[(int)(c->posY - c->dirY)][(int)c->posX] == '0')
		c->posY -= 0.3 * c->dirY;
}

int	ft_input(int key, t_game *game)
{
	if (key == KEY_UP)
		go_forward(&game->coords, game->map->m);
	if (key == KEY_DOWN)
		go_backward(&game->coords, game->map->m);
	if (key == KEY_LEFT)
		turn_left(&game->coords);
	if (key == KEY_RIGHT)
		turn_right(&game->coords);
	if (key == ESC)
		exit_game(game);
	else
		return (0);
	return (1);
}