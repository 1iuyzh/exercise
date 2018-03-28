#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define DEF_MODE S_IRUSR | S_IWUSR | S_IXUSR

int main() {
    int fd1, fd2;
    fd1 = open("baz.txt", O_WRONLY | O_TRUNC, 0);
    //close(fd1);
    fd2 = open("foo.txt", O_RDONLY | O_CREAT, DEF_MODE); //-1
    close(fd2);
    fd2 = open("baz.txt", O_RDWR, 0);
    printf("fd1 = %d\nfd2 = %d\n", fd1, fd2);
    return(0);
}