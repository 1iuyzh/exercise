#include <stdio.h>
/*
验证 getchar() != EOF 为 0 或 1
*/
int main() {
    int c; // EOF 的值为 -1

    while (c = getchar() != EOF)
        printf("%d", c);

    printf("%d", c); // Ctrl + Z
    c = getchar();
    return 0;
}
