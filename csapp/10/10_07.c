#include "../code/include/csapp.h"
#include "../code/src/csapp.c"

#undef MAXBUF
#define MAXBUF 4

#undef MAXLINE
#define MAXLINE 10

int main() {
    int n;
    rio_t rio;
    char buf[MAXLINE];
    
    Rio_readinitb(&rio, STDIN_FILENO);
    while ((n = Rio_readnb(&rio, buf, MAXBUF)) > 0)
        Rio_writen(STDOUT_FILENO, buf, n);

    exit(0);
}