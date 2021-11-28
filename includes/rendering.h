#ifndef _RENDERING_HPP_
#define _RENDERING_HPP_

#include "cub3D.h"
#include <math.h>
#include <stdbool.h>

enum e_keycode
{
	KEY_W = 13,
	KEY_S = 1,
	KEY_A = 0,
	KEY_D = 2,
	KEY_RIGHT = 124,
	KEY_LEFT = 123,
	ESC = 53
};

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_dataRay
{
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	int		texX;
	int		texY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	double	sideDistX;
	double	sideDistY;
	double	WallX;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	step;
	double	texPos;
}			t_dataRay;

typedef struct s_coords
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}				t_coords;

typedef struct s_texture
{
	t_vector	size;
	int			size_line;
	int			endian;
	int			bpp;
	void		*img;
	char		*addr;
}				t_texture;

typedef struct s_flags
{
	bool	w_key;
	bool	a_key;
	bool	s_key;
	bool	d_key;
	bool	right_key;
	bool	left_key;
}				t_flags;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_img 			img;
	t_map			*map;
	t_dataRay		ray;
	t_coords		coords;
	t_flags			flags;
	t_texture		*texs;
}	t_game;

void	start_game(t_game *game);
//void	game_init(t_game *game);
int		exit_game(t_game *game);
int		key_press(int key, t_game *game);
int		ft_update(t_game *game);
int		drawing_map(t_game *game);
void	go_forward(t_coords *c, char **map);
void	go_backward(t_coords *c, char **map);
void	turn_right(t_coords *c);
void	turn_left(t_coords *c);
void	go_left(t_coords *c, char **map);
void	go_right(t_coords *c, char **map);


void	graphics(t_game *game);

#endif