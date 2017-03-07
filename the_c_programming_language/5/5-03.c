#include <stdio.h>
void my_strcat(char *, char *);

int main(void) {
    int c;
    char s1[] = "programming ";
    char s2[] = "language";
    my_strcat(s1, s2);
    printf("%s\n", s1);
    c = getchar();
    return 0;
}

void my_strcat(char *s,char *t) {
    while (*s++ != '\0')
        ;
    s--;
    while ((*s++=*t++) != '\0')
        ;
}