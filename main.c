
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


char *get_next_line(int fd);

int main()
{
    int    fd;

        fd = open("test.txt", O_RDONLY);
        printf("GNL 1: %s\n", get_next_line(fd));
        printf("GNL 2: %s\n", get_next_line(fd));
        printf("GNL 3: %s\n", get_next_line(fd));
        printf("GNL 4: %s\n", get_next_line(fd));
        printf("GNL 5: %s\n", get_next_line(fd));
        printf("GNL 6: %s\n", get_next_line(fd));
        printf("GNL 7: %s\n", get_next_line(fd));
        printf("GNL 8: %s\n", get_next_line(fd));
        printf("GNL 9: %s\n", get_next_line(fd));
        close(fd);
}
