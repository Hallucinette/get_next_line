#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	char	*src;

	i = 0;
	src = (char *)s1;
	if (!(dest = malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char *ft_savelastline(char **line, char **tmp, int len)
{
    char *save;
    *line = ft_substr(*tmp, 0, len);
    save = *tmp;
    *tmp = ft_substr(save, len + 1, ft_strlen(save));
    free(save);
    return(*tmp);
}
/* char *ft_savelastline(char **line, char **tmp, int len)
{
    char *save;
    *line = ft_substr(*tmp, 0, len);
    save = ft_strdup(*tmp);
    free(*tmp);
    *tmp = ft_substr(save, len + 1, ft_strlen(save));
    free(save);
    return(*tmp);
}*/

int get_next_line(int fd, char **line)
{
    static char *tmp;
    char buffer[BUFFER_SIZE + 1];
    int nb_char;
    int len;

    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0
        || read(fd, buffer, 0) < 0)
        return(-1);
    if (tmp == NULL)
        if (!(tmp = ft_strdup("")))
            return(-1);
    while(((len = ft_instrchr(tmp, '\n')) == -1) && 
          (nb_char = read(fd, buffer, BUFFER_SIZE)) > 0)
    {    
        buffer[nb_char] = '\0';
        tmp = ft_fstrjoin(tmp, buffer);
    }
    if (len != -1)
    {
       if ((ft_savelastline(line, &tmp, len)) == NULL)
            return (-1);
    //printf("line = %s\n\n\n", *line);
     }
    else  
    {
        *line = tmp;    
        nb_char = 0;
        //free(tmp);
    }
    if (nb_char >= 1)
        nb_char = 1;
     printf("line = %s\n\n", *line);
    //printf("len = %d\n", len);



    //      printf("nb_char = %d\n", nb_char);
    //  printf("tmp = %s\n", tmp);
    return(nb_char);
}