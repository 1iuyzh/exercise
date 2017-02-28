#include <stdio.h>
#define MAX 1000
void expand(char s1[], char s2[]);

int main()
{
    int c;
    char t[MAX];
    char s[] = "-a-c-b-e-f-";
    expand(s, t);
    printf("result: %s\n", t);
    c = getchar();
    return 0;
}

void expand(char s1[], char s2[])
{
    int c = -1;
    int i, j, k;
    for (i=j=0; s1[i]!='\0'; i++)
    {
        if (s1[i]=='-' && s1[i+1]!='\0')
        {
            if (s1[i+1]>c && c>=0)
            {
                for (k=0; k<s1[i+1]-c; k++)
                    s2[j++] = c+k+1;
                c = c+k;
                ++i;
            }
            else
            {
                s2[j++] = s1[i];
                c = s1[i];
            }
        }
        else
        {
            s2[j++] = s1[i];
            c = s1[i];
        }
    }
    s2[j] = '\0';
}