#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);
int getfloat(float *);

int main(void) {
    int c;
    float f;
    while ((c=getfloat(&f))!=EOF && c!=0) {
        printf("f: %f\n", f);
    }
    c = getchar();
    return 0;
}

/* getfloat函数: 将输入中的下一个浮点数赋值给*pf */
int getfloat(float *pf) {
    int c, sign, next;
    float k;

    while (isspace(c=getch()))  // 跳过空白符
        ;
    if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {
        ungetch(c);
        return 0;   // 输入不是一个数字
    }
    sign = (c=='-')? -1 : 1;
    if (c=='+' || c=='-') {
        if (isdigit(next=getch()))
            c = next;
        else {
            ungetch(next);
            ungetch(c);
            return 0;
        }
    }
    for (*pf = 0; isdigit(c); c=getch())
        *pf = 10 * *pf + (c - '0');
    if (c == '.') {
        if (isdigit(next=getch()))
            c = next;
        else {
            ungetch(next);
            ungetch(c);
            return 0;
        }
    }
    for (k = 1; isdigit(c); c=getch(), k *= 10.0)
        *pf = 10 * *pf + (c - '0');
    *pf = sign * *pf / k;
    if (c != EOF)
        ungetch(c);
    return 1;
}

/* 取一个字符 */
int getch(void) {
    return (bufp > 0)? buf[--bufp] : getchar();
}

/* 把字符压回到输入中 */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
