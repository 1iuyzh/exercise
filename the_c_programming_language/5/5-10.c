#include <stdio.h>
#include <stdlib.h> // atof函数
#include <ctype.h>  // isdigit函数
#include <math.h>

#define NUMBER '0'  // 标识找到一个数
#define MAXVAL 100  // 栈大小
#define MAXOP 100   // 操作符或数字字符串所占字符上限

int sp = 0;         // 下一个空闲栈位置
double val[MAXVAL]; // 值栈

int getop(char *, char *);
void push(double);
double pop(void);

/* 逆波兰计算器 */
int main(int argc, char *argv[]) {
    double op2;
    int type;
    int i = 1;
    char s[MAXOP];
    if (argc < 2) {
        printf("Usage: expr 2 3 4 + x\n");
        return 0;
    }
    // 最后一个参数为空指针
    while (i < argc) {
        type = getop(*(argv + i), s);
        i++;
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            // '*'在cmd中默认表示当前所有文件。。
            case 'x':
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
    printf("\t%.8g\n", pop());
    return 0;
}

/* getop函数: 获取下一个运算符或数值操作数 */
int getop(char *s, char *t) {
    int i = 0;
    // 单字符操作符
    if (*(s + 1) == '\0' && !isdigit(*s)) {
        *t = *s;
        *(t + 1) = '\0';
        return *(s + 0);
    }
    while (isdigit(*(t + i) = *(s + i)))
        i++;
    if (*(t + i) == '\0') {
        return NUMBER;
    }
    else if (*(t + i) == '.') {
        i++;
        while (isdigit(*(t + i) = *(s + i)))
            i++;
        if (*(t + i) == '\0') {
            return NUMBER;
        }
    }
}

/* push函数: 把f压入到值栈中 */
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    }
    else
        printf("push: stack full, can't push %g\n", f);
}

/* pop函数: 弹出并返回栈顶的值 */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("pop: stack empty\n");
        return 0.0;
    }
}