/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:51:22 by frodney           #+#    #+#             */
/*   Updated: 2021/04/26 12:57:23 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*m1;
	const unsigned char	*m2;

	i = 0;
	m1 = (unsigned char *) s1;
	m2 = (unsigned char *) s2;
	while (i < n)
	{
		if ((unsigned char)m1[i] != (unsigned char)m2[i])
			return ((unsigned char)m1[i] - (unsigned char)m2[i]);
		i++;
	}
	return (0);
}
