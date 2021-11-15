/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:55:28 by frodney           #+#    #+#             */
/*   Updated: 2021/04/21 18:59:23 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!n || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *) src)[i];
		i++;
	}
	return (dst);
}
