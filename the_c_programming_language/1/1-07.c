#include <stdio.h>
/*
打印 EOF 的值
*/
int main() {
    int c;

    while ((c = getchar()) != EOF)
        printf("%c", c);

    printf("%d", c); // 打印 EOF
    c = getchar();
    return 0;
}
