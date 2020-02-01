#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    static char *tmp;
    char buffer[BUFFER_SIZE - 1];
    int nb_char;
    // char *buff;

    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
        return(-1);
   /* while(buff != ft_strchr(buff, '\n'))
    {
        tmp = read(fd, buff, BUFF_SIZE));
        ft_strjoin(tmp, buff);
    if (tmp[fd] = ft_strjoin(tmp[fd], buff);
		if (ft_strchr(auxfd[fd], '\n'))
			break ;
    } */

    if (!(tmp = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
         return(-1);
    while(((nb_char = read(fd, buffer, BUFFER_SIZE)) > 0) && !(ft_strchr(buffer, '\n')))
    {
        buffer[nb_char] = '\0';
        tmp = ft_strjoin(tmp, buffer);
        printf("%s\n", tmp);

    }
    // if (ft_strchr(tmp, '\n'))
    // {
    *line = ft_strdup(tmp);
    printf("line = %s\n", line);
    // }

    //printf("%s/n", buffer);
    printf("%d\n", nb_char);
    return (nb_char);


}