#include <stdio.h>
unsigned char lower(unsigned char alpha);

int main()
{
    int c;
    printf("result: %c\n", lower('C'));
    printf("result: %c\n", lower('c'));
    c = getchar();
    return 0;
}

unsigned char lower(unsigned char alpha)
{
    return (alpha >= 'A' && alpha <= 'Z')? alpha-'A'+'a' : alpha;
}
