#include <stdio.h>
#include <limits.h>

int main()
{
    int c;
    printf("Span of %s is %d ~ %d\n", "char", CHAR_MIN, CHAR_MAX);
    printf("Span of %s is %d ~ %d\n", "signed char", SCHAR_MIN, SCHAR_MAX);
    printf("Span of %s is %d ~ %d\n", "signed int", INT_MIN, INT_MAX);
    printf("Span of %s is %d ~ %d\n", "signed short", SHRT_MIN, SHRT_MAX);
    printf("Span of %s is %ld ~ %ld\n", "signed long", LONG_MIN, LONG_MAX);
    printf("Span of %s is %u ~ %u\n", "unsigned char", 0, UCHAR_MAX);
    printf("Span of %s is %u ~ %u\n", "unsigned int", 0, UINT_MAX);
    printf("Span of %s is %u ~ %u\n", "unsigned short", 0, USHRT_MAX);
    printf("Span of %s is %u ~ %u\n", "unsigned long", 0, ULONG_MAX);
    
    c = getchar();
    return 0;
}