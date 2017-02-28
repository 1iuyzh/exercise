#include <stdio.h>
unsigned rightrot(unsigned x, int n);

int main()
{
    int i, c;
    for (i=1; i<=64; i++)
        printf("result: %u\n", rightrot(1, i));
    c = getchar();
    return 0;
}

unsigned rightrot(unsigned x, int n)
{
    int i;

    for (i=0; i<n; i++)
        x = (x&1)<<31 |  x>>1;
    
    return x;
}
