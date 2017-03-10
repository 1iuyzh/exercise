#include <stdio.h>
#define MAX 1000
void escape(char s[], char t[]);
void esc(char s[], char t[]);

int main()
{
    int c;
    char s[MAX];
    char t[] = "li\nnu\tx";
    char o[] = "li\\nnu\\tx";
    escape(s, t);
    printf("result: %s\n", s);
    esc(s, o);
    printf("result: %s\n", s);
    c = getchar();
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    for (i=j=0; t[i]!='\0'; i++)
    {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
}

void esc(char s[], char t[])
{
    int i, j;
    for (i=j=0; t[i]!='\0'; i++)
    {
        if (t[i] == '\\')
        {
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    break;
            }
        }
        else
            s[j++] = t[i];
    }
}
