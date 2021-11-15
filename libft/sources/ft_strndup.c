/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:52:39 by frodney           #+#    #+#             */
/*   Updated: 2021/08/01 22:52:41 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*c;
	size_t	i;

	i = 0;
	c = malloc((n + 1) * sizeof(char));
	if (c == NULL || s == NULL)
		return (0);
	while (i < n && s[i] != '\0')
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
