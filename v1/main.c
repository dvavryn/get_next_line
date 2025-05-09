#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *s;
	int i = 10;
	while ((s = get_next_line(fd)))
	{
		printf(">>%s<<", s);
		free(s);
	}
	close(fd);
}