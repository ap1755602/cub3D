#include "cub3D.h"


int main (int argc, char*argv[])
{
	if (argc == 2)
	{
		parse(argv[1]);
		exit (0);
	}
	terminate("Error");
}