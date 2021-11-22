#ifndef _RENDERING_HPP_
#define _RENDERING_HPP_

#include "cub3D.h"

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
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
}				t_img_data;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_img_data 		img;
	t_map			map;
}	t_game;

void	start_game(t_game *game, t_map *map);
//void	game_init(t_game *game);
int		exit_game(t_game *game);
int		ft_input(int key, t_game *game);
int		ft_update(t_game *game);

#endif