#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd0, fd1, fd2, fd3;
    char pt[20];
    ssize_t n;
    fd0 = open("baz.txt", O_WRONLY, 0);
    fd1 = open("baz.txt", O_WRONLY | O_APPEND, 0);
    fd2 = open("baz.txt", O_WRONLY | O_TRUNC, 0);
    fd3 = open("baz.txt", O_RDONLY, 0);
    write(fd0, "0", 1);
    write(fd0, "0", 1);
    write(fd2, "2", 1);
    write(fd2, "2", 1);
    write(fd0, "0", 1); //220
    n = write(fd2, "2", 2); //222\0
    printf("%ld\n", n);
    write(fd1, "1", 1); //222\01
    n = read(fd3, pt, 6);
    printf("%ld %c\n", n, pt[4]); //5 1
    return (0);
}