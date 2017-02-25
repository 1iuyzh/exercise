#include <stdio.h>
/*
统计空格，换行符个数
*/
int main() {
    int c, n;

    for (n = 0; (c = getchar()) != EOF;){
        if (c == ' ' || c == '\n')
            ++n;
    }

    printf("%d", n);
    c = getchar();
    return 0;
}
