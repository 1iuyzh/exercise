#include "../include/csapp.h"

int main(void) {
    char c;
    while (read(STDIN_FILENO, &c, 1))
        write(STDOUT_FILENO, &c, 1);
    exit(0);
}