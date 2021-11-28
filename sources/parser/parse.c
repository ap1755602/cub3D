#include "cub3D.h"

t_map	*parse(char *cubFile)
{
	t_format	*t;
	t_map		*map;

	t = initStT();
	map = initMapS();
	char *ptr;
	ptr = ft_strchr(cubFile, '.');
	ptr++;
	if (ft_strncmp(ptr, "cub\0", 4))
		terminate("Error");
	int fd;
	fd = open(cubFile, O_RDONLY, 0); // check open
	if (!fd || read(fd, NULL, 0) < 0)
		terminate("Error");
	parseFormat(fd, &t);
	parseMap(fd, &map);
	map->format = t;
	return (map);
}
