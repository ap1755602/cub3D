/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:27:58 by frodney           #+#    #+#             */
/*   Updated: 2021/04/27 21:09:39 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[j]))
		j--;
	if (i >= j)
		return (ft_strdup(""));
	s = ft_substr(&s1[i], 0, j - i + 1);
	return (s);
}
