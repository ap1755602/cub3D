/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:03:29 by frodney           #+#    #+#             */
/*   Updated: 2021/04/29 03:15:16 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	space(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *s)
{
	int		minus;
	long	res;
	int		i;

	minus = 1;
	res = 0;
	i = space(s);
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			minus = -minus;
		i++;
	}
	while (ft_isdigit(s[i]) && s[i])
	{
		res *= 10;
		res += (s[i] - '0');
		i++;
	}
	return (minus * res);
}
