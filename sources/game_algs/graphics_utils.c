/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoanne <cjoanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:23:43 by cjoanne           #+#    #+#             */
/*   Updated: 2021/11/28 19:23:44 by cjoanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	apply_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_length) + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color_channel(t_texture *tex, int x, int y, int i)
{
	char			*dst;
	unsigned char	color;

	dst = tex->addr + ((y * tex->size_line) + x * (tex->bpp / 8));
	color = *(dst + i);
	return (color);
}

int	get_color(t_texture *tex, int x, int y)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_color_channel(tex, x, y, 3);
	r = get_color_channel(tex, x, y, 2);
	g = get_color_channel(tex, x, y, 1);
	b = get_color_channel(tex, x, y, 0);
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
