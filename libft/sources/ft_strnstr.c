/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:34:46 by frodney           #+#    #+#             */
/*   Updated: 2021/04/28 00:03:01 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *subs, size_t len)
{
	size_t	i;
	size_t	needle_len;
	char	*src;
	char	*cut_phrase;

	i = 0;
	src = (char *) str;
	cut_phrase = (char *) subs;
	if (*cut_phrase == 0)
		return (src);
	needle_len = ft_strlen(subs);
	while ((src[i] != 0) && (i + needle_len <= len))
	{
		if (cut_phrase[0] == src[i])
		{
			if ((ft_strncmp(&(src[i]), subs, needle_len) == 0))
				return (&(src[i]));
		}
		i++;
	}
	return (NULL);
}
