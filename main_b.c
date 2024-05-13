
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


char *get_next_line(int fd);

int main()
{
    int fd1;
    int fd2;

        fd1 = open("test1.txt", O_RDONLY);
        fd2 = open("test2.txt", O_RDONLY);

        printf("GNL 1: %s\n", get_next_line(fd1));
        printf("GNL 2: %s\n", get_next_line(fd1));
        printf("GNL 3: %s\n", get_next_line(fd1));
        printf("GNL 4: %s\n", get_next_line(fd1));
        printf("GNL 5: %s\n", get_next_line(fd1));
        printf("GNL 6: %s\n", get_next_line(fd1));
        printf("GNL 7: %s\n", get_next_line(fd1));
        printf("GNL 8: %s\n", get_next_line(fd1));
        printf("GNL 9: %s\n\n", get_next_line(fd1));

        printf("GNL 1: %s\n", get_next_line(fd2));
        printf("GNL 2: %s\n", get_next_line(fd2));
        printf("GNL 3: %s\n", get_next_line(fd2));
        printf("GNL 4: %s\n", get_next_line(fd2));
        printf("GNL 5: %s\n", get_next_line(fd2));
        printf("GNL 6: %s\n", get_next_line(fd2));
        printf("GNL 7: %s\n", get_next_line(fd2));
        printf("GNL 8: %s\n", get_next_line(fd2));
        printf("GNL 9: %s\n", get_next_line(fd2));

        close(fd1);
        close(fd2);
}
