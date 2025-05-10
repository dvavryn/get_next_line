#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd = 0;
	if (argc == 1)
		fd = open("test.txt", O_RDONLY);
	else
		fd = open(argv[1], O_RDONLY);
	char	*s;
	while ((s = get_next_line(fd)))
	{
		printf(">>%s<<", s);
		free(s);
	}
	close(fd);
}