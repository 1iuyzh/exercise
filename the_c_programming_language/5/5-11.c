#include <stdio.h>
// #define TAB 8   // 每TAB个位置出现一个制表符终止位

int main(int argc, char *argv[]) {
    int TAB = 8;
    int c, n, p;
    p = 0;
    if (argc > 1)
        TAB = *argv[1];
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            n = TAB - p%TAB;
            while (n > 0) {
                putchar(' ');
                n--;
                p++;
            }
        } else if (c == '\n') {
            putchar (c);
            p = 0;
        } else {
            putchar(c);
            p++;
        }
    }
    return 0;
}