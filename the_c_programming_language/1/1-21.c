/* entab  */
#include <stdio.h>
#define TAB 8   /* 每TAB个位置处出现一个制表符终止位 */

int main()
{
    /* n遇到的空格数，p当前位置 */
    int c, n, p, i;
    n = 0;
    p = 0;

    while ((c=getchar())!=EOF)
    {
        if (c==' ')
        {
            n++;
        }
        else
        {
            if (n > 0)
            {
                i = (p+n)/TAB - p/TAB;
                while (i > 0)
                {
                    //putchar('\t');
                    i--;
                }
                i = (p+n)%TAB;
                while (i > 0)
                {
                    putchar(' ');
                    i--;
                }
            }
            putchar(c);
            p++;
            if (c=='\n')
                p = 0;
            n = 0;
        }
    }

    return 0;
}