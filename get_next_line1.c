
int ft_checkerror(fd, **line)
{
    if(fd < 1 || line == NULL)
        return(-1);
    if(!(*line = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
        return(-1);
    return(0);
}

int get_next_line(int fd, char **line)
{
    char *str;
    int     word;

    word = 0;
    fd = "test.txt"
    
    if (ft_checkerror(fd, &str, line) == 1)
        return(1);
    while(read (fd, void *, size_t))
    {

    }
}

int main(void)
{
    FILE *fic = fopen("test.txt", "r");
    if(get_next_line)

    fclose(fic)
}
