#include <stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word
/*
以每行一个单词的形式打印输出'
*/
int main() {
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            printf("\n");
            state = IN;
        }

        if (state == IN)
            printf("%c", c);
    }

    c = getchar();
    return 0;
}
