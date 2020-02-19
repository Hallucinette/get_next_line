#include "get_next_line.h"

static char		*ft_del(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}

static int		ft_return(int rret, char **line)
{
	if (rret < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}

static char		*ft_line(char *cached, char **line, int *rret)
{
	int		pos;
	char	*temp;

	pos = 0;
	while (cached[pos] != '\n' && cached[pos] != '\0')
		pos++;
	if (cached[pos] == '\n')
	{
		*line = ft_substr(cached, 0, pos);
		temp = ft_strdup(cached + (pos + 1));
		free(cached);
		cached = temp;
		if (cached[0] == '\0')
			cached = ft_del(cached);
		*rret = 1;
	}
	else
	{
		*line = ft_strdup(cached);
		free(cached);
		cached = NULL;
		*rret = 0;
	}
	return (cached);
}

int				get_next_line(int fd, char **line)
{
	static char *cached[4096];
	char		*buff;
	int			rret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((rret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rret] = '\0';
		if (cached[fd] == NULL)
			cached[fd] = ft_strdup(buff);
		else
			cached[fd] = ft_strjoin(cached[fd], buff);
		if (ft_strchr(cached[fd], '\n'))
			break ;
	}
	free(buff);
	if ((rret < 0) || (rret == 0 && cached[fd] == NULL))
		return (ft_return(rret, line));
	cached[fd] = ft_line(cached[fd], line, &rret);
	return (rret);
}