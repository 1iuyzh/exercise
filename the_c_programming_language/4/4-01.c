#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
    int c;
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE)>0)
    {
        if ((c=strindex(line, pattern)) >= 0)
        {
            printf("%s: %d", line, c);
            found++;
        }
    }
    c = getchar();
    return found;
}

int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (i<lim-1 && (c=getchar())!=EOF && c!='\n')
        s[i++] = c;
    if (c=='\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    int location = -1;

    for (i=0; s[i]!='\0'; i++)
    {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k>0 && t[k]=='\0')
            location =  i;
    }
    return location;
}