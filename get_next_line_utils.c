#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int l;
	int save;

	l = 1;
	save = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		l = -1;
	}
	while (nb <= -10 || nb >= 10)
	{
		nb = nb / 10;
		l = l * 10;
	}
	while (l != 0)
	{
		ft_putchar(save / l + 48);
		save -= (save / l) * l;
		l /= 10;
	}
}

void	ft_putstr(char *str)
{
	int l;

	l = 0;
	while (str[l])
		ft_putchar(str[l++]);
}

void    ft_putstr_fd(int fd, char *str)
{
    write(fd, str, ft_strlen(str));
}
