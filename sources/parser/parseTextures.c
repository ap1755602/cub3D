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
		terminate("Error");
}

static void setValueTexture(char *str, char **value)
{
	char *ptr;
	char *trimed_path;

	if (*value)
		terminate("Error");
	ptr = ft_strchr(str, ' ');
	trimed_path = ft_strtrim(ptr, " ");
	if (!ptr || !trimed_path)
		terminate("Error");
	checkFileFormat(trimed_path);
	*value = trimed_path;
	free (str);
}

int		getRGB(char *red, char *green, char *blue)
{
	int R;
	int G;
	int B;

	R = ft_atoi(red);
	G = ft_atoi(green);
	B = ft_atoi(blue);
	return ((((R * 256) + G) * 256) + B);
}
static void setValueFC(char *str, int *i)
{
	char	*green;
	char	*blue;
	char	*red;


	if (*i != -1)
		terminate("Error");
	green = ft_strchr(str, ' ');
	red = ft_strtrim(green, " ");
	green = ft_strchr(red, ',');
	if (!green || !*(++green))
		terminate("Error");
	*(--green) = '\0';
	++green;
	blue = ft_strchr(green, ',');
	if (!blue || !*(++blue))
		terminate("Error");
	*(--blue) = '\0';
	++blue;
	if (!ft_isnum(red) || !ft_isnum(green) || !ft_isnum(blue))
		terminate("Error");
	*i = getRGB(red, green, blue);
	free (red);
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
		terminate("Error");
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

