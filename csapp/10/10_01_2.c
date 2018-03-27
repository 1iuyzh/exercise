#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2, fd3;
    char pt[20];
    ssize_t n;
    fd1 = open("baz.txt", O_WRONLY | O_APPEND, 0);
    fd2 = open("baz.txt", O_WRONLY | O_TRUNC, 0);
    fd3 = open("baz.txt", O_RDONLY, 0);
    //5
    n = write(fd1, "aaa", 5);
    printf("%ld\n", n);
    //2
    n = write(fd1, "bbb", 2);
    printf("%ld\n", n);
    //2
    n = write(fd2, "ccc", 2);
    printf("%ld\n", n);
    //cca\0\0bb
    n = read(fd3, pt, 6);
    printf("%s\n", pt);
    printf("%c\n", pt[5]);
    printf("%ld\n", n);
    //1
    n = read(fd3, pt, 2);
    printf("%ld\n", n);
    return (0);
}