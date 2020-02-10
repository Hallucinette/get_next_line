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

char		*ft_strjoinf(char const *s1, char const *s2)
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

int		ft_instrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[0] = '\0';
	if (len_s < start)
		return (dst);
	if (start + len > len_s)
		len = len_s - start;
	while (i < len)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}