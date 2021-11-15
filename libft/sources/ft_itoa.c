/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:15:31 by frodney           #+#    #+#             */
/*   Updated: 2021/04/28 21:13:28 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/

#include "libft.h"

static char	*ft_swap(char *tmp)
{
	int		i;
	int		b;
	char	c;

	i = 0;
	b = ft_strlen(tmp);
	while (i < --b)
	{
		c = tmp[b];
		tmp[b] = tmp[i];
		tmp[i] = c;
		i++;
	}
	return (&tmp[0]);
}

static void	ft_minus(char *tmp, int min, int i)
{
	if (min == -1)
	{
		tmp[i] = '-';
		tmp[++i] = '\0';
	}
	else
		tmp[i] = '\0';
	ft_swap (tmp);
}

char	*ft_itoa(int n)
{
	int		minus;
	char	tmp[11];
	int		i;

	minus = 1;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		minus = -1;
		n = -n;
	}
	while (n > 0)
	{
		tmp[i++] = n % 10 + '0';
		n /= 10;
	}
	ft_minus(tmp, minus, i);
	return (ft_strdup(tmp));
}
