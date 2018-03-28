#include "../code/include/csapp.h"

int main() {
    int fd1, fd2;
    fd1 = open("foobar.txt", O_WRONLY, 0);
    write(fd1, "1", 1);
    close(fd1);
    fd2 = open("foobar.txt", O_WRONLY | O_TRUNC, 0);
    write(fd2, "2", 1);
    close(fd2);
    exit(0);
}