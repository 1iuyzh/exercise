#include "../code/include/csapp.h"

int main(int argc, char **argv) {
    unsigned int addr;
    sscanf(argv[1], "%x", &addr);

    struct in_addr inaddr;
    inaddr.s_addr = htonl(addr);
    printf("%s\n", inet_ntoa(inaddr));

    exit(0);
}