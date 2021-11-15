/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 15:51:06 by frodney           #+#    #+#             */
/*   Updated: 2021/04/29 19:32:33 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*str)
		str++;
	if (c == '\0')
		return ((char *)str);
	while (--str >= s)
	{
		if (c == *str)
			return ((char *)str);
	}
	return (NULL);
}
