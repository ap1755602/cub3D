#include "cub3D.h"

void parse(char *cubFile)
{
	t_format	*t;
	t_map		*map;

	t = initStT();
	map = initMapS();
	char *ptr;
	ptr = ft_strchr(cubFile, '.');
	ptr++;
	if (ft_strncmp(ptr, "cub\0", 4))
		terminate("Error: usage: ./cub3D source_file.cub");
	int fd;
	fd = open(cubFile, O_RDONLY, 0); // check open
	if (!fd || read(fd, NULL, 0) < 0)
		terminate("Error: non valid .cub file");
	parseFormat(fd, &t);
	parseMap(fd, &map);
}
