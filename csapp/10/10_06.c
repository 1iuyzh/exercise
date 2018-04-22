#include "../code/include/csapp.h"

int main() {
    int fd1, fd2;

    fd1 = open("foo.txt", O_RDONLY, 0); // fd1 3
    fd2 = open("bar.txt", O_RDONLY, 0); // fd2 4
    close(fd2);
    fd2 = open("baz.txt", O_RDONLY, 0); // fd2 4
    printf("fd2 = %d\n", fd2);
    exit(0);
}