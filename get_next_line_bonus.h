#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h> 
# include <unistd.h>
# include <stddef.h> 
# include <stdint.h>
# include <string.h>
# include <fcntl.h>


char	*get_next_line(int fd);
char    *get_stash_from_buffer(int fd, char *stash, char *buffer);
char    *extract_line(char *stash, char *line);
char    *extract_remaining_stash(char *stash);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int     find_newline_index(char *stash);

#endif 