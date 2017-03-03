#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main(void) {
    int c;
    printf("result: %f\n", atof("-123.456E2"));
    c = getchar();
    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign, sign2, j;

    for (i=0; isspace(s[i]); i++)
        ;
    sign = (s[i]=='-')? -1 : 1;
    if (s[i]=='+' || s[i]=='-')
        i++;
    for (val=0.0; isdigit(s[i]); i++)
        val = 10.0*val + (s[i]-'0');
    if (s[i]=='.')
        i++;
    for (power=1.0; isdigit(s[i]); i++)
    {
        val = 10.0*val + (s[i]-'0');
        power *= 10.0;
    }
    if (s[i]=='e' || s[i]=='E')
        i++;
    sign2 = (s[i]=='-')? -1 : 1;
    if (s[i]=='+' || s[i]=='-')
        i++;
    for (j=0; isdigit(s[i]); i++)
        j = 10*j + (s[i]-'0');
    while (j>0)
    {
        if (sign2==-1)
            power *= 10.0;
        else
            power /= 10.0;
        j--;
    }
    return sign * val / power;
}