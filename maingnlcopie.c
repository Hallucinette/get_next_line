#include "gnlcopie.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int i = 0;
	//fd = open("test.txt", O_RDONLY);
	//fd = open("testvacio.c", O_RDONLY);
	//fd = open("testvacio1.txt", O_RDONLY);
	//fd = open("test1.txt", O_RDONLY);
	fd = open("fdfalse.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		printf("%d", i++);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	system("leaks a.out");
	return (0);
}