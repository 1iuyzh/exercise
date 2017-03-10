#include <stdio.h>
/* 将x中从第p位开始的n个(二进制)位设置为y中最右边n位的值，x其余各位保持不变 */
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    int c;
    printf("result: %u\n", setbits(16, 3, 3, 15));
    c = getchar();
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ~(~(~0<<n)<<(p-n+1))) | (y & ~(~0<<n))<<(p-n+1);
}
