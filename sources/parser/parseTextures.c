#include "cub3D.h"

t_format *initStT(void)
{
	t_format *t;

	t = (t_format *)malloc(sizeof (t_format));
	t->NO = NULL;
	t->SO = NULL;
	t->WE = NULL;
	t->EA = NULL;
	t->F = -1;
	t->C = -1;
	return (t);
}

static void checkFileFormat(char *str) // how to check valid and do we need ./ (../?)
{
	size_t i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(&(str[i]), ".xpm\0", 5))
		terminate(ft_strjoin("Error: non valid file format", &str[i]));
}

static void setValueTexture(char *str, char **value)
{
	char *ptr;
	char *trimed;

	if (*value)
		terminate(ft_strjoin("Error: double trying set val: ", str));
	ptr = ft_strchr(str, ' ');
	trimed = ft_strtrim(ptr, " "); // ! malloc
	if (!ptr || !trimed) // || ft_strncmp(trimed, "./", 2))
		terminate(ft_strjoin("Error: non valid texture file", trimed));
	// add here check . / after ./
	checkFileFormat(trimed);
	*value = trimed;
}

int ft_isnum(char *str)
{
	while (*str)
	{
		if (*str > 47 && *str < 58)
		{
			++str;
			continue ;
		}
		else
			return (0);
	}
	return (1);
}

int		getRGB(int R, int G, int B)
{
	return ((((R * 256) + G) * 256) + B);
}
static void setValueFC(char *str, int *i)
{
	char	*ptr;
	char	*ptr1;
	char	*trimed;
	int		R;
	int		G;
	int		B;

	if (*i != -1)
		terminate(ft_strjoin("Error: double trying set val: ", str));

	ptr = ft_strchr(str, ' ');
	trimed = ft_strtrim(ptr, " ");
	ptr = ft_strchr(trimed, ',');
	if (!ptr || !*(++ptr))
		terminate("Error: non valid color format");
	*(--ptr) = '\0';
	++ptr;
	ptr1 = ft_strchr(ptr, ',');
	if (!ptr1 || !*(++ptr1))
		terminate("Error: non valid color format");
	*(--ptr1) = '\0';
	++ptr1;
	if (!ft_isnum(trimed) || !ft_isnum(ptr) || !ft_isnum(ptr1))
		terminate("Error: non valid color format");
	R = ft_atoi(trimed);
	G = ft_atoi(ptr);
	B = ft_atoi(ptr1);
	*i = getRGB(R, G, B);
	free (str);
}

static void setFormat(char *str, t_format **t)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		setValueTexture(str, &(*t)->NO);
	}
	else if (!ft_strncmp(str, "SO ", 3))
		setValueTexture(str, &(*t)->SO);
	else if (!ft_strncmp(str, "WE ", 3))
		setValueTexture(str, &(*t)->WE);
	else if (!ft_strncmp(str, "EA ", 3))
		setValueTexture(str, &(*t)->EA);
	else if (!ft_strncmp(str, "F ", 2))
		setValueFC(str, &(*t)->F);
	else if (!ft_strncmp(str, "C ", 2))
		setValueFC(str, &(*t)->C); 
	else
		terminate(ft_strjoin("Error: unrecognizable format: ", str));
}

 void parseFormat(int fd, t_format **t)
{
	int	counter;
	char *currStr;

	counter = 6;
	while(counter && get_next_line(fd, &currStr))
	{
		if (!ft_strncmp(currStr, "\0", 1))
		{
			free (currStr);
			continue;
		}
		counter--;
		setFormat(currStr, t);
	}
	printf("----------print_txtres---------\n");
	printf("NO %s\n", (*t)->NO);
	printf("SO %s\n", (*t)->SO);
	printf("WE %s\n", (*t)->WE);
	printf("EA %s\n", (*t)->EA);
	printf("F %d\n", (*t)->F);
	printf("C %d\n", (*t)->C);
}

