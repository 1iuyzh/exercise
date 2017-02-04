#include <stdio.h>
/*
打印输入中各个字符出现频度的直方图
*/
int main() {
    int c, i, j;
    int nc[128];

    for (i = 0; i < 128; ++i)
        nc[i] = 0;

    while ((c = getchar()) != EOF) {
        ++nc[c];
    }

    for (i = 0; i < 128; i++) {
        if (i >= 32 && i <= 126)
            printf("%3c:%4d", i, nc[i]);
        else
            printf("%3d:%4d", i, nc[i]);

        for (j = 0; j < nc[i]; j++)
            printf("*");
        printf("\n");
    }

    c = getchar();
    return 0;
}