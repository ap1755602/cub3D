/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 21:28:51 by frodney           #+#    #+#             */
/*   Updated: 2021/08/01 22:54:02 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.
*/

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
			continue ;
		}
		i++;
	}
	return (words);
}

int	lw(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_free(char **splits, int j)
{
	while (--j >= 0)
		free (splits[j]);
	free (splits);
	return (NULL);
}

static char	**to_short(const char *s, char **splits, char c, int *j)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			splits[*j] = (char *)malloc(sizeof(char ) * (lw(&s[i], c) + 1));
			if (!splits[*j])
				return (ft_free(splits, *j));
			ft_strlcpy(splits[*j], &s[i], (lw(&s[i], c) + 1));
			while (s[i] != c && s[i])
				i++;
			*j += 1;
			continue ;
		}
		i++;
	}
	return (splits);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		words;
	char	**splits;

	j = 0;
	if (!s)
		return (NULL);
	words = count_words (s, c);
	splits = ((char **)malloc(sizeof (char *) * (words + 1)));
	if (!splits)
		return (NULL);
	splits = to_short (s, splits, c, &j);
	splits[j] = NULL;
	return (splits);
}
