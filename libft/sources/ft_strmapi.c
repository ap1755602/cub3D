/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:59:00 by frodney           #+#    #+#             */
/*   Updated: 2021/04/28 21:14:04 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Applies the function ’f’ to each character of the
string ’s’ to create a new string (with malloc(3))
resulting from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*gg;

	if (!s || !f)
		return (NULL);
	gg = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!gg)
		return (NULL);
	i = 0;
	while (s[i])
	{
		gg[i] = f(i, s[i]);
		++i;
	}
	gg[i] = '\0';
	return (gg);
}
