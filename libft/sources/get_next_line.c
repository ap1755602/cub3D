/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frodney <frodney@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:53:06 by frodney           #+#    #+#             */
/*   Updated: 2021/08/01 22:53:07 by frodney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sprt(char **newline)
{
	char	*line;
	char	*ptrn;
	char	*ptr;

	ptrn = ft_strchr(*newline, '\n');
	if (ptrn == NULL)
	{
		line = ft_strndup(*newline, ft_strlen(*newline));
		free(*newline);
		*newline = NULL;
		return (line);
	}
	line = ft_strndup(*newline, ((ft_strlen(*newline)) - (ft_strlen(ptrn))));
	ptrn++;
	ptr = ft_strndup(ptrn, ft_strlen (ptrn));
	free(*newline);
	*newline = ptr;
	return (line);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	long		rb;
	static char	*newline;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	rb = 1;
	if (newline == NULL)
		newline = ft_strndup("", 0);
	while (rb && !ft_strchr(newline, '\n'))
	{
		buf = (char *) malloc(BUFFER_SIZE + 1);
		rb = read(fd, buf, BUFFER_SIZE);
		buf[rb] = '\0';
		newline = ft_strjoin(newline, buf);
		free (buf);
	}
	*line = ft_sprt(&newline);
	if (rb == 0)
		return (0);
	return (1);
}
