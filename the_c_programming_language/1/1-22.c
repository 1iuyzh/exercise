#include <stdio.h>
#define N 10    // N列后折行

int main()
{
    int c, p;
    int s[N];
    p = 0;

    while ((c=getchar())!=EOF)
    {
        int i;
        if (c=='\n')
        {
            if (p==0)
                putchar('\n');
            else
            {
                for (i=0; i<p; i++)
                    putchar(s[i]);
                putchar('\n');
            }
            p = 0;
        }
        else
        {
            s[p] = c;
            p++;
            if (p==N)
            {
                p = p-1;
                while ((s[p]==' ' || s[p]=='\t') && p>=0)
                    p--;
                if (p==-1)
                {
                    putchar('\n');
                }
                else
                {
                    for (i=0; i<=p; i++)
                        putchar(s[i]);
                    putchar('\n');
                }
                p = 0;
            }
        }
    }
    return 0;
}