#include "libft.h"
#include <errno.h>
//klklklklk
void	terminate(char *error_message)
{
	ft_putendl_fd(error_message, 2);
	exit(errno);
}