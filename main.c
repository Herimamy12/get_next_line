#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	fd = open("file", O_RDONLY);
	line = get_next_line(fd);
	return (0);
}