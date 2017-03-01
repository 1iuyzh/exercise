#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int c;
    char buffer[20];
    printf("INT_MIN: %d\n", INT_MIN);
    itoa(INT_MIN, buffer);
    printf("buffer: %s\n", buffer);
    c = getchar();
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    sign = n;

    i = 0;
    do {
        s[i++] = abs(n%10) + '0';
    } while (n/=10);
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