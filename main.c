#include "get_next_line.h"

 int		main()
{
	int		fd;
	char	*line;
	int ret;
	//fd = open("test.txt", O_RDONLY);
	fd = open("fd.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// printf("\nlen = %d\n", len);
        // printf("tmp = %s\n", tmp);
       // printf("line = %s\n", line);
		free(line);
        // printf("nb_char = %d\n", nb_char);
	}
	free(line);
	close(fd);
	system("leaks a.out");
	return (0);
}