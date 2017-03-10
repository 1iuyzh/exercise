#include <stdio.h>
int any(char left[], char right[]);

int main()
{
    int c;
    char left[] = "helloworld";
    char right[] = "win";
    char str[] = "is";
    printf("result: %d\n", any(left, right));
    printf("result: %d\n", any(left, str));
    c = getchar();
    return 0;
}

int any(char left[], char right[])
{
    int i, j;

    for (i=0; left[i]!='\0'; i++)
    {
        for (j=0; right[j]!='\0'; j++)
        {
            if (left[i]==right[j])
                return i;
        }
    }

    return -1;
}
