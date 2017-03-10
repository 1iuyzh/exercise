/* C程序简单错误查找，不带注释 */
#include <stdio.h>
#define MAX 1000    // 程序最大字符

int main()
{
    int c, i, j, k, error;
    int s[MAX];
    error = 0;
    // 模拟栈
    int h[10];  // 最大括号嵌套
    for (j=0; j<10; j++)
        h[j] = 0;

    while ((c=getchar())!=EOF)
    {
        s[i] = c;
        i++;
    }

    k = 0;
    for (j=0; j<i; j++)
    {
        if (s[j] == ')')
        {
            if (h[k-1] == 1)
            {
                h[k-1] = 0;
                k--;
            }
            else
                error = 1;
        }
        else if (s[j] == ']')
        {
            if (h[k-1] == 2)
            {
                h[k-1] = 0;
                k--;
            }
            else
                error = 1;
        }
        else if (s[j] == '}')
        {
            if (h[k-1] == 3)
            {
                h[k-1] = 0;
                k--;
            }
            else
                error = 1;
        }
        if (s[j] == '(')
        {
            h[k] = 1;   // 圆括号
            k++;
        }
        else if (s[j] == '[')
        {
            h[k] = 2;   // 圆括号
            k++;
        }
        else if (s[j] == '{')
        {
            h[k] = 3;   // 花括号
            k++;
        }
    }

    for (j=0; j<i; j++)
        putchar(s[j]);

    if (h[0] != 0)
        error = 1;
    
    if (error == 1)
        printf("The program has error!\n");

    c = getchar();
    return 0;
}
