#include <stdio.h>
#define MAX 100

int main()
{
    int i, c;
    int s[MAX];
    int lim = MAX;
    for (i=0; i<lim-1 && (c=getchar())!='\n' && c!=EOF; i++)
        s[i] = c;
    for (i=0; i<lim-1; i++)
    {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;
        s[i] = c;
    }
    c = getchar();
    return 0;
}