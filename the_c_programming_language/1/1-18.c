#include <stdio.h>
#define MAXLINE 1000
int getline(char s[], int maxline);

int main()
{
    int i;
    int len;                // current line length
    char line[MAXLINE];     // current input line
    char ch;

    while ((len = getline(line, MAXLINE)) >= 0) // > 0
    {
        i = len-1;
        while (line[i]==' ' || line[i]=='\t')
        {
            line[i] = '\0';
            i--;
        }
        printf("%sf\n", line);  // f for flag
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
