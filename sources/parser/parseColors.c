/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseColors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 13:39:54 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 13:39:55 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		getRGB(char *red, char *green, char *blue)
{
	int R;
	int G;
	int B;

	R = ft_atoi(red);
	G = ft_atoi(green);
	B = ft_atoi(blue);
	return ((((R * 256) + G) * 256) + B);
}
void    setValueFC(char *str, int *i)
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
	*i = getRGB(red, green, blue);
	free (red);
	free (str);
}
