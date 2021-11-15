/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:54:04 by frodney           #+#    #+#             */
/*   Updated: 2021/08/01 12:45:30 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	nb;
	size_t	b;

	i = 0;
	nb = 0;
	b = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (i < b)
		dest[i++] = s1[nb++];
	nb = ft_strlen(s2);
	i = 0;
	while (i < nb)
		dest[b++] = s2[i++];
	dest[b] = '\0';
	free(s1);
	return (dest);
}
