/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amepocch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 06:42:29 by amepocch          #+#    #+#             */
/*   Updated: 2020/02/20 06:42:32 by amepocch         ###   ########.fr       */
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

char		*ft_saveline(char **line, char **tmp, int len)
{
	char	*save;

	*line = ft_substr(*tmp, 0, len);
	save = *tmp;
	*tmp = ft_substr(save, len + 1, ft_strlen(save));
	free(save);
	return (*tmp);
}

int			ft_check_error(int fd, char **line, char **tmp)
{
	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	if (*tmp == NULL)
	{
		if (!(*tmp = ft_strdup("")))
			return (-1);
	}
	return (1);
}

int			ft_free(char **line, char **tmp)
{
	*line = *tmp;
	*tmp = NULL;
	free(*tmp);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			nb_char;
	int			len;

	if ((ft_check_error(fd, line, &tmp[fd])) == -1)
		return (-1);
	while (((len = ft_instrchr(tmp[fd], '\n')) == -1) &&
			(nb_char = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[nb_char] = '\0';
		tmp[fd] = ft_fstrjoin(tmp[fd], buffer);
	}
	if (nb_char == -1)
		if ((ft_free(line, &tmp[fd])) == 0)
			return (-1);
	if (len != -1)
		ft_saveline(line, &tmp[fd], len);
	else
	{
		if ((ft_free(line, &tmp[fd])) == 0)
			return (0);
	}
	return (1);
}
