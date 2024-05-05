
#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash = NULL;
    char buffer[BUFFER_SIZE + 1];
    char *line = NULL;
    char *temp;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0) // If fd is invalid, BUFFER_SIZE is invalid, or read() returns -1
        return NULL;
    
    if (!stash) { 
        stash = strdup("");
    }

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(stash, buffer);
        free(stash);
        stash = temp;
        if (ft_strchr(buffer, '\n')) {
            break;
        }
    }
    if (bytes_read < 0) {
        free(stash);
        return NULL;
    }

    if (*stash == '\0') {
        free(stash);
        stash = NULL;
        return NULL;
    }

    char *new_line = ft_strchr(stash, '\n'); // Find the first occurrence of '\n' in stash
    if (new_line) { // If '\n' is found
        *new_line = '\0'; // Replace '\n' with '\0'
        line = strdup(stash); // Duplicate stash to line
        temp = strdup(new_line + 1); // Duplicate the rest of the string to temp
        free(stash);
        stash = temp;
    } 
    else if (new_line == stash) { // If '\n' is the first character in stash
        line = strdup(""); // Duplicate an empty string to line
        temp = strdup(stash + 1); // Duplicate the rest of the string to temp
        free(stash);
        stash = temp;
    }
    else if(!ft_strchr(stash, '\n') && *stash != '\0') 
    { // No newline found and stash is not empty
    line = strdup(stash);
    free(stash);
    stash = NULL;
    return line;
    }
    else { // If '\n' is not found
        line = strdup(stash); // Duplicate stash to line
        free(stash);
        stash = NULL;
    }

    return line;
}


