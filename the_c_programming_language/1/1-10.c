#include <stdio.h>
/*
将输入复制到输出，把回退符替换为 \b，把换行符替换为 \n，把反斜杠替换为 \\，把制表符替换为 \t
*/
int main() {
    int c;

    while ((c = getchar()) != EOF){
        if (c == '\b')
            printf("\\b");
        else if (c == '\n')
            printf("\\n");
        else if (c == '\t')
            printf("\\t");
        else
            printf("%c", c);
    }

    c = getchar();
    return 0;
}
