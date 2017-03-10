#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop函数: 获取下一个运算符或数值操作数 */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c!='.')
        return c;   // 不是数
    i = 0;
    if (isdigit(c)) // 收集整数部分
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}