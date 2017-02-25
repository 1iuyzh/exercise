#include <stdio.h>

#define IN  1 // inside a word
#define OUT 0 // outside a word
/*
单词计数程序
*/
int main() {
    int c, n, state;

    state = OUT;
    n = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++n;
        }
    }

    printf("%d\n", n);
    c = getchar();
    return 0;
}
