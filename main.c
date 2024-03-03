#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	*buff;
	char	*buff2;
	size_t	count;
	ssize_t	res;

	count = 6;
	fd = open("file", O_RDONLY);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	buff2 = (char *)malloc(sizeof(char) * BUFFER_SIZE);
/*	for (int i = 0; i < 3; i++)
	{	*/
		res = read(fd, buff, BUFFER_SIZE);
		printf ("-->%s\n", buff);
		res = read(fd, buff, BUFFER_SIZE);
		printf (">>>%s\n", buff);
		res = read(fd, buff2, BUFFER_SIZE);
		printf (">--%s", buff2);
//	}
	return (0);
}