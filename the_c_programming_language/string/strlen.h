#include <stddef.h>

size_t strlen(const char* src) {
    if (src == NULL)
        return -1;
    int len = 0;
    while (*src++ != '\0')
        len++;
    return len;
}