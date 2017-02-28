#include <stdio.h>
/* 将x中从第p位开始的n个(二进制)位求反，x其余各位保持不变 */
unsigned invert(unsigned x, int p, int n);

int main()
{
    int c;
    printf("result: %u\n", invert(16, 3, 3));
    c = getchar();
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    // ~(~0<<n)<<(p-n+1)
    return (x & ~(~(~0<<n)<<(p-n+1))) | (~(x & ~(~0<<n)<<(p-n+1)) & ~(~0<<n)<<(p-n+1));
}
