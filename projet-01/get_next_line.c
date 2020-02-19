/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 22:03:02 by amepocch          #+#    #+#             */
/*   Updated: 2020/02/19 21:06:47 by amepocch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *s1)
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

/* char		*ft_saveline(char **line, char **tmp, int len)
{
	char	*save;

	*line = ft_substr(*tmp, 0, len);
	save = *tmp;
	//if (!(save = malloc (sizeof(char) * (ft_strlen(*tmp) + 1))))
	//		return(NULL);
	free(*tmp);
	*tmp = ft_substr(save, len + 1, ft_strlen(save));
	//free(save);
	//printf("2");
	//printf("%s", *line);
	return (*tmp);
} */

char *ft_saveline(char **line, char **tmp, int len)
{
    char *save;

    *line = ft_substr(*tmp, 0, len);
    save = *tmp;
    *tmp = ft_substr(save, len + 1, ft_strlen(save));
    free(save);
    return(*tmp);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			nb_char;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	if (tmp[fd] == NULL)
		if (!(tmp[fd] = ft_strdup("")))
			return (-1);
		//if (!(tmp[fd] = malloc (sizeof(fd) * (ft_strlen(buffer) + 1))))
		//	return(-1);
	while (((len = ft_instrchr(tmp[fd], '\n')) == -1) &&
			(nb_char = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nb_char] = '\0';
		tmp[fd] = ft_fstrjoin(tmp[fd], buffer);
	}
	if (nb_char == -1)
	{
		*line = ft_strdup("");
		if (tmp[fd])
			free(tmp[fd]);
		tmp[fd] = NULL;
		return (-1);
	}
	if (len != -1)
	{
		//printf("1");
		ft_saveline(line, &tmp[fd], len);
	}
	else
	{
		*line = tmp[fd];
		if (tmp[fd])
			//free(tmp[fd]);
		tmp[fd] = NULL;
		free(tmp[fd]);
		return (0);
	}
	return (1);
}
