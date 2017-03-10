#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void);
void ungetch(int);
int getint(int *);

int main(void) {
    int c;
    int n;
    while ((c=getint(&n))!=EOF && c!=0) {
        printf("n: %d\n", n);
    }
    c = getchar();
    return 0;
}

/* getint函数: 将输入中的下一个整形数赋值给*pn */
int getint(int *pn) {
    int c, sign, next;

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
    for (*pn = 0; isdigit(c); c=getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
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