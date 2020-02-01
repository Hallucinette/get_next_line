#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strcat(char *str1, char *str2)
{
	int		len;
	int		i;

	len = ft_strlen(str1);
	i = 0;
	while (str2[i])
	{
		str1[len + i] = str2[i];
		i++;
	}
	str1[len + i] = '\0';
	return (str1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		total_size;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	if (!(new = malloc(total_size + 1)))
		return (NULL);
	new[0] = '\0';
	new = ft_strcat(new, (char *)s1);
	new = ft_strcat(new, (char *)s2);
	free((char *)s1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

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