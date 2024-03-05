#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	char	*line2;

	fd = open("file", O_RDONLY);
	for (int i = 0; i < 10; i++)
	{
		line = get_next_line(fd);
		printf ("%s", line);
	}
	close(fd);
	return (0);
}