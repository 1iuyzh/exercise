#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
int getline(char s[], int maxline);

int main()
{
    int len;                // current line length
    char line[MAXLINE];     // current input line
    char ch;

    while ((len = getline(line, MAXLINE)) >= 0)
    {
        if (len > 8)
        {
            printf("%s\n", line);
        }
    }

    ch = getchar();
    return 0;
}

int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    s[i] = '\0';
    return i;
}
