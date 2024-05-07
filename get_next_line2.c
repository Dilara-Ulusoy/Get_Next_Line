#include "get_next_line.h"

char *read_file(int fd, char *result) // Read the file and return the result as a single string 
{
    char *buffer;
    int byte_read;

    if (!result)
        result = ft_calloc(1, 1);
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    while ((byte_read = read(fd, buffer, BUFFER_SIZE)) > 0) 
    {
        buffer[byte_read] = '\0'; // Null terminate the buffer
        result = ft_strjoin(result, buffer); // Join the buffer to the result
        if (ft_strchr(buffer, '\n'))
            break;
    }
    if (byte_read < 0)
    {
        free(result);
        return NULL;
    }
    free(buffer);
    return result;
}

char *ft_line(char *buffer) // Return the line from the buffer 
{
    char *line;
    int i;
    int len;

    len = ft_strlen(buffer);
    line = ft_calloc(len + 1, sizeof(char));
    if (!line)
        return NULL;
    i = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0')
    {
        line[i] = buffer[i];
        i++;
    }
    while (buffer[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    return line;
}


char *get_next_line(int fd)
{
    static char *stash; // Static variable to store the remaining string
    char *line; // Pointer to the line

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0) // If the file descriptor is invalid, the buffer size is invalid, or read() returns -1
        return NULL;
    stash = read_file(fd, stash);
    if (!stash)
        return NULL;
    line = ft_line(stash); // Get the line from the stash
    return line;
}

