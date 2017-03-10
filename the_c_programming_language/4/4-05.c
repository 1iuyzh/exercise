#include <stdio.h>
#include <stdlib.h>     // atof函数
#include <ctype.h>      // isdigit函数
#include <math.h>
#include <string.h>

#define MAXOP 100       // 操作数或运算符的最大长度
#define NUMBER 0        // 标识找到一个数
#define IDENTIFIER 1    // 标识找到一个操作符
#define BUFSIZE 100     // 缓冲区
#define MAXVAL 100      // 栈的最大深度
#define TRUE 1
#define FALSE 0

char buf[BUFSIZ];       // 用于ungetch函数的缓冲区
int bufp = 0;           // buf中下一个空闲位置
int sp = 0;             // 下一个空闲栈位置
double val[MAXVAL];     // 值栈

int getch(void);
void ungetch(int c);
int getop(char []);
void push(double);
double pop(void);
void showTop(void);
void duplicate(void);
void swapItems(void);
void clearStack(void);
void dealWithName(char []);

/* 逆波兰计算器 */
int main(void) {
    int c;
    int type;
    double op2;
    char s[MAXOP];

    while ((type=getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case IDENTIFIER:
                dealWithName(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2)
                    push(fmod(pop(), op2));
                else
                    printf("Error: Division by zero!\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    c = getchar();
    return 0;
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

/* getop函数: 获取下一个运算符或数值操作数 */
int getop(char s[]) {
    int i = 0;
    int c, next;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (isalpha(c)) {
        i = 0;
        while (isalpha(s[i++] = c))
            c = getch();
        s[i-1] = '\0';
        if (c!=EOF)
            ungetch(c);
        return IDENTIFIER;
    }
    if (!isdigit(c) && c!='.' && c!='-')
        return c;   // 不是数
    if (c == '-') {
        next = getch();
        if (!isdigit(next) && next != '.')
            return c;
        c = next;
    }
    else
        c = getch();
    while (isdigit(s[++i] = c))
        c = getch();
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* push函数: 把f压入到值栈中 */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("push: stack full, can't push %g\n", f);
}

/* pop函数: 弹出并返回栈顶的值 */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("pop: stack empty\n");
        return 0.0;
    }
}

/* showTop函数: 打印栈顶元素 */
void showTop(void) {
    if (sp > 0)
        printf("Top of stack contains: %8g\n", val[sp=1]);
    else
        printf("The stack is empty!\n");
}

/* duplicate函数: 复制栈顶元素 */
void duplicate(void) {
    double temp = pop();
    push(temp);
    push(temp);
}

/* swapItems函数: 交换栈顶两个元素的值*/
void swapItems(void) {
    double item1 = pop();
    double item2 = pop();
    
    push(item1);
    push(item2);
}

/* clearStack函数: 清空栈*/
void clearStack(void) {
    sp = 0;
}

/* dealWithName函数 */
void dealWithName(char s[]) {
    double op2;

    if (!strcmp(s, "sin"))
        push(sin(pop()));
    else if (!strcmp(s, "cos"))
        push(cos(pop()));
    else if (!strcmp(s, "exp"))
        push(exp(pop()));
    else if (!strcmp(s, "pow")) {
        op2 = pop();
        push(pow(pop(), op2));
    }
    else
        printf("%s is not a supported function.\n", s);
}