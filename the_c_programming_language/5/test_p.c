#include <stdio.h>

int main(void) {
    int c;
    char (*p1)[10];
    printf("%d\n", sizeof(p1));
    char *p2[10];
    printf("%d\n", sizeof(p2));
    c = getchar();
    return 0;
}
