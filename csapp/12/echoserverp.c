#include "csapp.h"
void echo(int connfd);

//SIGCHLD处理程序
void sigchld_handler(int sig) {
    //由于Unix信号不排队, 需要回收多个僵死进程
    while (waitpid(-1, 0, WHOHANG) > 0);
    return;
}

int main(int argc, char **argv) {
    int listenfd, connfd, port;
    socklen_t clientlen = sizeof(struct sockaddr_in);
    struct sockaddr_in clientaddr;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(0);
    }
    port = argv[1];

    Signal(SIGCHLD, sigchld_handler);
    listenfd = Open_listenfd(port);
    while (1) {
        connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
        if (Fork() == 0) {
            Close(listenfd);
            echo(connfd);
            Close(connfd);
            exit(0);
        }
        //必须关闭它的已连接描述符, 避免存储器泄漏
        //直到父子进程的connfd都关闭了, 到客户端的连接才会终止
        Close(connfd);
    }
}