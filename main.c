#include "get_next_line.h"

 int		main()
{
	int		fd;
	char	*line;
	int ret;
	//fd = open("test.txt", O_RDONLY);
	//d = open("testvacio.c", O_RDONLY);
	//fd = open("testvacio1.txt", O_RDONLY);
	//fd = open("test1.txt", O_RDONLY);
	fd = open("fdfalse.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// printf("\nlen = %d\n", len);
        // printf("tmp = %s\n", tmp);
        printf("%s\n", line);
		free(line);
        // printf("nb_char = %d\n", nb_char);
	}
    printf("%s\n", line);
	free(line);
	close(fd);
	system("leaks a.out");
	return (0);
}