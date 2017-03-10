#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000   // 进行排序的最大文本行数
#define MAXLEN 1000     // 每个输入文本行的最大长度

char *lineptr[MAXLINES];    // 指向文本行的指针数组
char lines[MAXLINES][MAXLEN];

int readlines(char *[], int);
int readlines2(char lines[][MAXLEN], int maxlines);
void writelines(char *[], int);
int getline(char [], int);
void my_qsort(char *[], int, int);
void swap(char *[], int, int);

int main(void) {
    int c;
    int nlines; // 读取的输入行数目
    if ((nlines = readlines2(lines, MAXLINES)) >= 0) {
        my_qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        c = getchar();
        return 0;
    } else {
        printf("error: input too big to sort.\n");
        c = getchar();
        return 1;
    }
}

int getline(char s[], int lim) {
    int i, c;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    s[i] = '\0';
    return i;
}

int readlines2(char lines[][MAXLEN], int maxlines) {
    int len, nlines;
    nlines = 0;
    while ((len = getline(lines[nlines], MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
    return nlines;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            // line[len-1] = '\0'; //删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i=0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void my_qsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i<=right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    my_qsort(v, left, last-1);
    my_qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}