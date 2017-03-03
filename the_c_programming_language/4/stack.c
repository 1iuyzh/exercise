#include <stdio.h>
#include "calc.h"
#define MAXVAL 100
int sp = 0;
double cal[MAXVAL];

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
