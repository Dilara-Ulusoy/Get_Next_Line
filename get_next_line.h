#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

//#define BUFFER_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>

char    *ft_strdup(const char *s);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char const *s1, char const *s2);
char    *get_next_line(int fd);

#endif 