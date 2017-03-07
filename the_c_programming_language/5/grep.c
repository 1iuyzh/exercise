#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *, int);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while (getline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s\n", line);
                found++;
            }
    return found;
}

int getline(char *line, int max) {
    int i = 0;
    int c;
    while (i < max - 2 && (c = getchar()) != EOF && c != '\n')
        *(line + i++) = c;
    *(line + i++) = '\n';
    *(line + i) = '\0';
    return i;
}