#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
    static char *tmp[4096];
    char buffer[BUFFER_SIZE + 1];
    int nb_char;
    int len;

    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
        return(-1);
    if (*tmp == NULL)
        if (!(*tmp = ft_strdup("")))
            return(-1);
    while((ft_strchr(*tmp, '\n') == -1) && 
          (nb_char = read(fd, buffer, BUFFER_SIZE)) > 0)
    {    
        buffer[nb_char] = '\0';
        *tmp = ft_strjoin(*tmp, buffer);
    }
    if ((len = ft_strchr(*tmp, '\n')) != -1)
     {
        *line = ft_substr(*tmp, 0, len);
        *tmp = ft_substr(*tmp, len + 1, ft_strlen(*tmp));
     }
    else  
        *line = ft_substr(*tmp, 0, ft_strlen(*tmp));
         printf("line = %s\n", *line);
     return (nb_char);
}


    //      printf("\nlen = %d\n", len);
    //      printf("tmp = %s\n", tmp);
    //      printf("nb_char = %d\n", nb_char);