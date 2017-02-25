#include <stdio.h>
/*
将输入复制到输出，并把其中连续空格用一个空格代替
*/
int main() {
    int c1, c2;
    c1 = 'a';

    while ((c2 = getchar()) != EOF){
        if (c1 == ' ' && c2 == ' ')
            continue;
        printf("%c", c2);
        c1 = c2;
    }

    c1 = getchar();
    return 0;
}
