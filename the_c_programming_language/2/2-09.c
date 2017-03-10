#include <stdio.h>
int bitcount(unsigned x);

int main()
{
    int c;
    printf("result: %d\n", bitcount(16));
    c = getchar();
    return 0;
}

int bitcount(unsigned x)
{
    int i;
    for (i=0; x; i++)
        x&=(x-1);
    return i;
}
