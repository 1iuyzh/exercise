#include <stdio.h>
#define MAXLINE 1000
int reverse(char s[], int maxline);

int main()
{
    int len;                // current line length
    char line[MAXLINE];     // current input line
    char ch;

    while ((len = reverse(line, MAXLINE)) >= 0) // > 0
    {
        printf("%s\n", line);
    }
    
    ch = getchar();
    return 0;
}

int reverse(char s[], int lim)
{
    int c, i, j, temp;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    s[i] = '\0';

    if (i == 0)
        return i;
    
    for (j=0; j<=(i-1)/2; j++)
    {
        temp = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = temp;
    }
    return i;
}