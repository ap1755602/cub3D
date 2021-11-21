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
#include <stdio.h>

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

//#include "get_next_line.h"

//char	*get_save(char *save) ///////////////////////////////
//{
//	char	*rtn;
//	int		i;
//	int		j;
//
//	i = 0;
//	j = 0;
//	if (!save)
//		return (0);
//	while (save[i] && save[i] != '\n')
//		i++;
//	if (!save[i])
//	{
//		free(save);
//		return (0);
//	}
//	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
//		return (0);
//	i++;
//	while (save[i])
//		rtn[j++] = save[i++];
//	rtn[j] = '\0';
//	free(save);
//	return (rtn);
//}
//
//char	*get_line(char *str)
//{
//	int		i;
//	char	*rtn;
//
//	i = 0;
//	if (!str)
//		return (0);
//	while (str[i] && str[i] != '\n')
//		i++;
//	if (!(rtn = malloc(sizeof(char) * (i + 1))))
//		return (0);
//	i = 0;
//	while (str[i] && str[i] != '\n')
//	{
//		rtn[i] = str[i];
//		i++;
//	}
//	rtn[i] = '\0';
//	return (rtn);
//}
//
//int		get_next_line(int fd, char **line)
//{
//	char			*buff;
//	static char		*save;
//	int				reader;
//
//	reader = 1;
//	if (fd < 0 || !line || BUFFER_SIZE <= 0)
//		return (-1);
//	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
//		return (-1);
//	while (!has_return(save) && reader != 0)
//	{
//		if ((reader = read(fd, buff, BUFFER_SIZE)) == -1)
//		{
//			free(buff);
//			return (-1);
//		}
//		buff[reader] = '\0';
//		save = join_str(save, buff);
//	}
//	free(buff);
//	*line = get_line(save);
//	save = get_save(save);
//	if (reader == 0)
//		return (0);
//	return (1);
//}