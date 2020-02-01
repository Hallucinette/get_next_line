

int ft_checkerror(fd, **line)
{
    if(fd < 1 || line == NULL)
        return(-1);
    if(!(*line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
        return(-1);
    return(0);
}

int main()
{
    int fd;
    int ret;
    int buf[BUF_SIZE + 1];

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("open error\n");
        return (1);
    }
    while (ret = read(fd, buf, BUF_SIZE))
    {
        buf[ret] = '\n';
        ft_putnbr(ret);
        ft_putstr(buf);
    }
    ft_putnbr(ret);

    if (close(fd) == 1)
    {
        ft_putstr("close error\n");
        return(1);
    }
    return(0);
}