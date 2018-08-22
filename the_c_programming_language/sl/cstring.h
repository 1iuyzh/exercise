#include "stddef.h"

char *strcpy(char *dst, char *src) {
    char *cp = dst;
    while (*cp++ = *src++);
    return dst;
}

char *strcat(char *dst, const char *src) {
    char *cp = dst;
    while (*cp)
        cp++;
    while (*cp++ = *src++);
    return dst;
}

int strcmp(const char *src, const char *dst) {
    int ret = 0;
    while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
        ++src, ++dst;
    if (ret < 0)
        ret = -1;
    else if (ret > 0)
        ret = 1;
    return ret;
}

char *strstr(const char *str1, const char *str2) {
    char *cp = (char *)str1;
    char *s1, *s2;
    if (!*str2)
        return ((char *)str1);
    while (*cp) {
        s1 = cp;
        s2 = (char *)str2;
        while (*s1 && *s2 && !(*s1 - *s2))
            s1++, s2++;
        if (!*s2)
            return cp;
        cp++;
    }
    return NULL;
}