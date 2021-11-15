/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 22:15:51 by frodney           #+#    #+#             */
/*   Updated: 2021/04/26 14:07:45 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dl;
	size_t	i;

	dl = 0;
	while (dst[dl] != 0 && dl < n)
		dl++;
	i = dl;
	while (i + 1 < n && (src[i - dl] != '\0'))
	{
		dst[i] = src[i - dl];
		i++;
	}
	if (i < n)
		dst[i] = '\0';
	return (dl + ft_strlen(src));
}
