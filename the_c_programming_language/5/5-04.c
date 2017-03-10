#include <stdio.h>
int my_strlen(char *);
int my_strcmp(char *, char *);
int my_strend(char *, char *);

int main(void) {
    int c;
    char s1[] = "c_programming";
    char s2[] = "programming";
    char s3[] = "language";
    printf("result: %d\n", my_strend(s1, s2));
    printf("result: %d\n", my_strend(s1, s3));
    c = getchar();
    return 0;
}

int my_strlen(char *s) {
    int i;
    for (i = 0; *s != '\0'; i++, s++)
        ;
    return i;
}

int my_strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int my_strend(char *s, char *t) {
    int s_len;
    int t_len;
    s_len = my_strlen(s);
    t_len = my_strlen(t);
    if (s_len >= t_len) {
        s = s + s_len - t_len;
        if (!my_strcmp(s, t))
            return 1;
    }
    return 0;
}
