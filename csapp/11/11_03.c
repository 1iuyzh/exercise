#include "../code/include/csapp.h"

int main(int argc, char **argv) {
    struct in_addr inaddr;
    if (inet_aton(argv[1], &inaddr)) {
        printf("0x%x\n", ntohl(inaddr.s_addr));
    }
    exit(0);
}