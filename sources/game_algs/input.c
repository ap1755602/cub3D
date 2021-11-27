#include "rendering.h"

void	turn_left(t_coords *c)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = c->dirX;
	c->dirX = c->dirX * cos(ROTATE_SPEED) - c->dirY * sin(ROTATE_SPEED);
	c->dirY = oldDirX * sin(ROTATE_SPEED) + c->dirY * cos(ROTATE_SPEED);
	oldPlaneX = c->planeX;
	c->planeX = c->planeX * cos(ROTATE_SPEED) - c->planeY * sin(ROTATE_SPEED);
	c->planeY = oldPlaneX * sin(ROTATE_SPEED) + c->planeY * cos(ROTATE_SPEED);
}

void	turn_right(t_coords *c)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = c->dirX;
	c->dirX = c->dirX * cos(-ROTATE_SPEED) - c->dirY * sin(-ROTATE_SPEED);
	c->dirY = oldDirX * sin(-ROTATE_SPEED) + c->dirY * cos(-ROTATE_SPEED);
	oldPlaneX = c->planeX;
	c->planeX = c->planeX * cos(-ROTATE_SPEED) - c->planeY * sin(-ROTATE_SPEED);
	c->planeY = oldPlaneX * sin(-ROTATE_SPEED) + c->planeY * cos(-ROTATE_SPEED);
}

void	go_forward(t_coords *c, char **map)
{
	if (map[(int)c->posY][(int)(c->posX + c->dirX)] == '0')
		c->posX += MOVE_SPEED * c->dirX;
	if (map[(int)(c->posY + c->dirY)][(int)c->posX] == '0')
		c->posY += MOVE_SPEED * c->dirY;
}

void	go_backward(t_coords *c, char **map)
{
	if (map[(int)c->posY][(int)(c->posX - c->dirX)] == '0')
		c->posX -= MOVE_SPEED * c->dirX;
	if (map[(int)(c->posY - c->dirY)][(int)c->posX] == '0')
		c->posY -= MOVE_SPEED * c->dirY;
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_UP)
		game->flags.w_key = 1;
	if (key == KEY_DOWN)
		game->flags.s_key = 1;
	if (key == KEY_LEFT)
		game->flags.a_key = 1;
	if (key == KEY_RIGHT)
		game->flags.d_key = 1;
	if (key == ESC)
		exit_game(game);
	else
		return (0);
	return (1);
}