#include <stddef.h>

char* strcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL)
        return NULL;
    char* res = dest;
    while ((*dest++ = *src++) != '\0');
    return res;
}