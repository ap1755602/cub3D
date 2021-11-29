/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:16:33 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/29 13:22:40 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "parser.h"
# include <math.h>
# include <stdbool.h>

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
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		texx;
	int		texy;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	sidedistx;
	double	sidedisty;
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	step;
	double	texpos;
}			t_dataRay;

typedef struct s_coords
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
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
	t_img			img;
	t_map			*map;
	t_coords		coords;
	t_flags			flags;
	t_texture		*texs;
}	t_game;

void	start_game(t_game *game);
int		exit_game(t_game *game);
int		key_unpress(int key, t_game *game);
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
void	ray_calcs(t_game *game, t_dataRay *r, int x);
void	step_and_side_dist_calcs(t_game *game, t_dataRay *r);
void	dda_algorithm(t_game *game, t_dataRay *r);
void	lines_calcs(t_game *game, t_dataRay *r);
void	which_wall(t_game *game, t_dataRay *r);
void	assign_texture_pixels(t_game *game, t_dataRay *r, int x);

void	apply_pixel(t_img *img, int x, int y, int color);
int		get_color_channel(t_texture *tex, int x, int y, int i);
int		get_color(t_texture *tex, int x, int y);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif