#include "libft.h"

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