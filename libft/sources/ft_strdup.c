/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:02:22 by frodney           #+#    #+#             */
/*   Updated: 2021/04/26 23:14:39 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;

	c = malloc((ft_strlen(s) + 1) * sizeof(char));
	ft_strlcpy(c, s, ft_strlen(s) + 1);
	return (c);
}
