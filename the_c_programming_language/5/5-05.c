#include <stdio.h>
#include <string.h>
void my_strncpy(char *, char *, int);
void my_strncat(char *, char *, int);
int my_strncmp(char *, char *, int);
int my_strlen(char *);

int main(void) {
    int c;
    // 注意: 内存分配怎么做
    char s1[20];
    char s2[20] = "programming";
    char s3[20] = "languagestudy";
    char s4[20] = "programscience";
    my_strncpy(s1, s2, 7);
    printf("strncpy() result: %s\n", s1);
    my_strncat(s2, s3, 8);
    printf("strncat() result: %s\n", s2);
    printf("strncmp() result: %d\n", my_strncmp(s2, s4, 7));
    c = getchar();
    return 0;
}

int my_strlen(char *s) {
    int i;
    while (*s++ != '\0')
        i++;
    return i;
}

int my_strncmp(char *s, char *t, int n) {
    int i = 0;
    for (; *s == *t; s++, t++) {
        i++;
        if (*s == '\0' || i == n)
            return 0;
    }
    return *s - *t;
}

void my_strncat(char *s, char *t, int n) {
    while (*s)
        s++;
    my_strncpy(s, t, n);
}

void my_strncpy(char *s, char *t, int n) {
    int i = 0;
    while (*s++ = *t++) {
        i++;
        if (i == n) {
            *s = '\0';
            break;
        }
    }
}
