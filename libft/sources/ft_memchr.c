/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:46:46 by frodney           #+#    #+#             */
/*   Updated: 2021/04/26 12:54:36 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*right;

	i = 0;
	right = (char *)s;
	while (i < n)
	{
		if (right[i] == (char) c)
			return (right + i);
		i++;
	}
	return (NULL);
}
