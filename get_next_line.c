#include "get_next_line.h"

char    *ft_line(int fd, char *buffer)
{
    char    *line;
    long   bytes;
    char    *tmp;

    line = malloc(BUFFER_SIZE * sizeof(char) + 1);
    bytes = read(fd, line, BUFFER_SIZE);
    if (bytes == 0)
    {
        free(line);
        return (NULL);
    }
    if (strchr(line, '\n') != NULL)
    {
        tmp = malloc(sizeof(line));
        tmp = ft_trim_line(line);

    }
}

char    *get_next_line(int fd)
{
    static char **buffer;
    char        *line;
    if (!*buffer)
        *buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
    if (!*buffer)
        return (NULL);
    line = malloc(BUFFER_SIZE * sizeof(char) + 1);
    if (!line)
        return (NULL);
    line = ft_line(fd, *buffer);
    while (ft_strchr(*buffer, '\n') == NULL)
        line = ft_line(fd, *buffer);
}