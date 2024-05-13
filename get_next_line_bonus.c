#include "get_next_line_bonus.h"


char *get_next_line(int fd)
{
    static char *stash[MAX_FD];
    char *line;
    char *buffer;

    line = NULL;
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!buffer)
    {
        free(stash[fd]);
        return (stash[fd] = 0);
    }
    if (!buffer || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd >= MAX_FD)
    {
        free(buffer);
        free(stash[fd]);
        stash[fd] = NULL;
        return (NULL);  
    }
    stash[fd] = get_stash_from_buffer(fd, stash[fd], buffer);
    if (!stash[fd] || *stash[fd] == '\0')
    {
        free(stash[fd]);
        return (stash[fd] = NULL);
    }
    line = extract_line(stash[fd], line);
    if (!line)
    {
        free(stash[fd]);
        return (stash[fd] = NULL);
    }
    stash[fd] = extract_remaining_stash(stash[fd]);
    if (!stash[fd])
    {
        free(line);
        free(stash[fd]);
        return (stash[fd] = NULL);
    }
    return (line);
}

char *get_stash_from_buffer(int fd, char *stash, char *buffer)
{
    int nbytes;
    char    *temp;

    nbytes = 1;
    if (!stash)
    {
        stash = ft_strdup("");
        if (!stash) 
        {
            free(buffer);
            return (NULL);
        }
    }
    while (nbytes > 0)
    {
        nbytes = read(fd, buffer, BUFFER_SIZE);
        if (nbytes == -1)
        {
            free(stash);
            free(buffer);
            return (NULL);
        }
        buffer[nbytes] = '\0';
        temp = ft_strjoin(stash, buffer);
        if (!temp)
        {
            free(stash);
            free(buffer);
            return (NULL);
        }
        stash = temp;
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return (stash);
}
char *extract_line(char *stash, char *line)
{
    int len;
    int i;

    len = find_newline_index(stash);
    i = 0;
    if (!stash)
        return (NULL);
    line = malloc((len + 1) * sizeof(char));
    if (!line)
        return (NULL);
    while (i < len)
    {
        line[i] = stash[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char *extract_remaining_stash(char *stash)
{
    char *remaining_stash;
    int i;
    int len;

    i = 0;
    if (!stash)
        return (NULL);
    len = find_newline_index(stash);
    remaining_stash = malloc((ft_strlen(stash) - len + 1) * sizeof(char));
    if (!remaining_stash)
    {
        free(stash);
        return (NULL);
    }
    while (stash[len + i] != '\0')
    {
        remaining_stash[i] = stash[len + i];
        i++;
    }
    free(stash);
    remaining_stash[i] = '\0';
    return (remaining_stash);
}

int find_newline_index(char *stash)
{
    int i;

    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\n')
        i++;
    return (i);
}
