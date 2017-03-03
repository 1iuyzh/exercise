#include <stdio.h>
#include <stdlib.h>     // atof函数
#include <ctype.h>      // isdigit函数
#include <math.h>
#include <string.h>

#define MAXOP 100       // 操作数或运算符的最大长度
#define NUMBER 0        // 标识找到一个数
#define IDENTIFIER 1    // 标识找到一个操作符
#define ENDSTRING 2     // new
#define MAX_ID_LEN 32   // 变量名长度
#define MAXVARS 26      // 可用变量数，A-Z
#define TRUE 1
#define FALSE 0
#define BUFSIZE 100     // 缓冲区
#define MAXVAL 100      // 栈的最大深度

struct varType {
    char name[MAX_ID_LEN];
    double val;
};
char buf[BUFSIZE];       // 用于ungetch函数的缓冲区
int bufp = 0;           // buf中下一个空闲位置
int sp = 0;             // 下一个空闲栈位置
double val[MAXVAL];     // 值栈
int pos = 0;
struct varType last;    // 上一个变量

int getch(void);
void ungetch(int c);
int getop(char []);
void push(double);
double pop(void);
void showTop(void);
void duplicate(void);
void swapItems(void);
void clearStacks(struct varType[]); // new
void dealWithName(char [], struct varType[]);
void dealWithVar(char [], struct varType[]);

/* 逆波兰计算器 */
int main(void) {
    int i, type;                       // 接收getop()的返回值
    double op2;
    char s[MAXOP];                  // 操作数或者运算符
    struct varType var[MAXVARS];    // 变量表

    clearStacks(var);

    while ((type=getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case IDENTIFIER:
                dealWithName(s, var);
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
            case '?':
                showTop();
                break;
            case '#':
                duplicate();
                break;
            case '~':
                swapItems();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case ENDSTRING: // 对变量赋值？
                break;
            case '=':       // 赋值语句 1 A =
                pop();
                var[pos].val = pop();
                last.val = var[pos].val;
                push(last.val);
                break;
            case '<':
                printf("The last variable used was: %s (value == %g)\n",last.name, last.val);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
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

/* clearStacks函数: 同时清空栈和变量表 */
void clearStacks(struct varType var[]) {
    int i;
    sp = 0;
    for(i=0; i<MAXVARS; i++) {
        var[i].name[0] = 'A' + i;
        var[i].val = 0.0;
    }
}

/* dealWithName函数 */
void dealWithName(char s[], struct varType var[]) {
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
        dealWithVar(s, var);
}

/* dealWithVar函数 */
void dealWithVar(char s[], struct varType var[]) {
    int i = 0;

    while (var[i].name[0] != '\0' && i < MAXVARS-1) {
        if (!strcmp(s, var[i].name)) {
            strcpy(last.name, s);
            last.val = var[i].val;
            push(var[i].val);   // 出现变量将其值压入栈
            pos = i;
            return;
        }
        i++;
    }
}

/* getch函数: 取一个字符 */
int getch(void) {
    return (bufp > 0)? buf[--bufp] : getchar();
}

/* ungetch函数: 把字符压回到输入中 */
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

    // skip whitespace
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
        return IDENTIFIER;  // 找到一个操作符或变量名
    }
    if (!isdigit(c) && c!='.' && c!='-') {
        if (c == '=' && (next = getch()) == '\n')
        {
            ungetch('\0');
            return c;   
        }
        if (c == '\0')
            return ENDSTRING;
        return c;   // 返回运算符
    }
    if (c == '-') {
        if (!isdigit(next=getch()) && next != '.')
            return c;   // 返回减号
        c = next;   // 读取负数
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
    return NUMBER;  // 找到一个数字
}
