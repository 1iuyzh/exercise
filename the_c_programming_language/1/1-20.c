/* detab  */
#include <stdio.h>
#define TAB 8   /* 每TAB个位置处出现一个制表符终止位 */

int main()
{
    /* n需要替换的空格数，p当前位置 */
    int c, n, p;
    p = 0;

    while ((c=getchar())!=EOF)
    {
        if (c=='\t')
        {
            n = TAB - p%TAB;
            while (n>0)
            {
                putchar(' ');
                n--;
                p++;
            }
        }
        else if (c=='\n')
        {
            putchar(c);
            p = 0;
        }
        else
        {
            putchar(c);
            p++;
        }
    }

    return 0;
}
