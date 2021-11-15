/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 22:43:37 by frodney           #+#    #+#             */
/*   Updated: 2021/04/27 14:46:01 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	c = (char *)malloc(count * size);
	if (c == NULL)
		return (NULL);
	ft_bzero (c, count * size);
	return (c);
}
