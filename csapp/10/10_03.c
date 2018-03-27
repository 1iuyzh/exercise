#include "../code/include/csapp.h"

int main() {
    int fd;
    char c;

    fd = open("foobar.txt", O_RDONLY, 0);
    if (fork() == 0) {
        read(fd, &c, 1);
        exit(0);
    }
    wait(NULL);
    read(fd, &c, 1);
    printf("c = %c\n", c); // c = o
    exit(0);
}