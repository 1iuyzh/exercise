#include <stdio.h>
#include <string.h>
void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int c;
    char buffer[10];
    int i;
    for (i=2; i<36; i++)
    {
        itob(255, buffer, i);
        printf("Demical 255 in base %-2d: %s\n", i, buffer);
    }
    c = getchar();
    return 0;
}

void itob(int n, char s[], int b)
{
    static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    int sign = 1;
    if (n < 0)
    {
        sign = -1;
        n = -n;
    }
    do {
        s[i++] = digits[n%b];
    } while ((n/=b)>0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for(i=0, j=strlen(s)-1; i<j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}