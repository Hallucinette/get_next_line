#include "get_next_line.h"

 /* int			main(int argc, char **argv)
 {
 	int		fd;
// int		i = 0;
 	char		*line;

	if (argc == 2)
 	{
 		fd = open(argv[1], O_RDONLY);
 		while ((get_next_line(fd, &line)) == 1)
 		{
 			// printf("[%d] %s\n", i++, line);
 		}
 		close(fd);
 	}
 	return (0);
 } */

 int		main()
{
	int		fd;
	char	*line;
	fd = open("test.txt", O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("line : %s\n", line);
	}
	close(fd);
	return (0);
}