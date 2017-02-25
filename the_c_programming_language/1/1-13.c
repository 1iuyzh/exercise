#include <stdio.h>

#define IN  1 // 在单词内
#define OUT 0 // 在单词外
/*
打印输入中单词长度的直方图
*/
int main() {
    int c, i, j, state;
    int nw[20];

    for (i = 0; i < 20; ++i)
        nw[i] = 0;

    i = j = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            state = IN;
            ++i;
        }
        else if (state == IN) {
            ++nw[i-1];
            i = 0;
            state = OUT;
        }
    }

    for (i = 0; i < 20; ++i) {
        printf("%2d:%4d", i+1, nw[i]);
        for (j = 0; j < nw[i]; ++j)
            printf("*");
        printf("\n");
    }

    c = getchar();
    return 0;
}
