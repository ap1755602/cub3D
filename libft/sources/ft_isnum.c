/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:33:15 by frodney           #+#    #+#             */
/*   Updated: 2021/11/28 14:33:23 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char *str)
{
	while (*str)
	{
		if (*str > 47 && *str < 58)
		{
			++str;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}
