#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	int st;
	char *line;

	while ((st = get_next_line(fd, &line)) > 0)
	{
		printf("%d -- %s\n", st, line);
		free(line);
	}
	printf("%d -- %s\n", st, line);
	free(line);
	close(fd);
	system("leaks a.out");
}
