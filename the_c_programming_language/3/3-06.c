#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
void reverse(char s[]);
void itoa(int n, char s[], int w);

int main()
{
    int c, i;
    char buffer[20];
    for (i=0; i<1000; i++)
    {
        itoa(i, buffer, 3);
        printf("buffer: %s\n", buffer);
    }
    c = getchar();
    return 0;
}

void itoa(int n, char s[], int w)
{
    int i, sign;
    sign = n;

    i = 0;
    do {
        s[i++] = abs(n%10) + '0';
    } while (n/=10);
    if (sign < 0)
        s[i++] = '-';
    if (i < w)
    {
        for (; i<w; i++)
            s[i] = ' ';
    }
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
