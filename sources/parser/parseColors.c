/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseColors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:39:54 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 14:15:21 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_rgb(char *red, char *green, char *blue)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(red);
	g = ft_atoi(green);
	b = ft_atoi(blue);
	return ((((r * 256) + g) * 256) + b);
}

void	set_value_f_c(char *str, int *i)
{
	char	*green;
	char	*blue;
	char	*red;

	if (*i != -1)
		terminate("Error");
	green = ft_strchr(str, ' ');
	red = ft_strtrim(green, " ");
	green = ft_strchr(red, ',');
	if (!green || !*(++green))
		terminate("Error");
	*(--green) = '\0';
	++green;
	blue = ft_strchr(green, ',');
	if (!blue || !*(++blue))
		terminate("Error");
	*(--blue) = '\0';
	++blue;
	if (!ft_isnum(red) || !ft_isnum(green) || !ft_isnum(blue))
		terminate("Error");
	*i = get_rgb(red, green, blue);
	free (red);
	free (str);
}
