/* 去掉程序中的注释，这里以换行结束注释，即注释不在行内 */
#include <stdio.h>
#define MAX 1000    // 程序最大占用字符数
#define COMMENT1 0  // 在注释1内
#define COMMENT2 1  // 在注释2内
#define NONE 2      // 注释外

int main()
{
    int i, j, c1, c2, status;
    int s[MAX];
    i = 0;
    c1 = '\n';
    status = NONE;

    while ((c2=getchar())!=EOF)
    {
        if (status == COMMENT1)
        {
            if (c2 == '\n')
            {
                status = NONE;
                c1 = '\n';
            }
        }
        else if (status == COMMENT2)
        {
            if (c2 == '\n')
            {
                status = NONE;
                c1 = '\n';
            }
        }
        else if (status == NONE)
        {
            if (c1=='/' && c2=='/')
                status = COMMENT1;
            else if (c1=='/' && c2=='*')
                status = COMMENT2;
            else
                s[i] = c1;
                i++;
                c1 = c2;
        }
    }

    for (j=0; j<i; j++)
        putchar(s[j]);

    c2 = getchar();
    return 0;
}
