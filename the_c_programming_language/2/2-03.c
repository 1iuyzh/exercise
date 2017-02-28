/* htoi函数，把由16进制数字组成的字符串，转换为等价的整形数 */
#include <stdio.h>
int htoi(char s[]);

int main()
{
    int c;
    char s[] = "0Xff";
    printf("num: %d\n", htoi(s));
    c = getchar();
    return 0;
}

int htoi(char s[])
{
    int i, n;

    n = 0;
    for (i=2; (s[i]>='a' && s[i]<='f') || (s[i]>='A' && s[i]<='F') || (s[i]>='0' && s[i]<='9'); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
        else if (s[i] >= 'A' && s[i] <= 'F')
            n = 16 * n + (s[i] - 'A' + 10);
        else if (s[i] >= '0' && s[i] <= '9')
            n = 16 * n + (s[i] - '0');
    }

    return n;
}