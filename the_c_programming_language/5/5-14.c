#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000   // 待排序的最大行数
#define MAXLEN 1000

char *lineptr[MAXLINES];    // 指向文本行的指针

int readlines(char *[], int);
void writelines(char *[], int);
int getline(char [], int);
void my_qsort(void *[], int, int, int, int (*comp)(void *, void *));
int numcmp(char *, char *);
void swap(void *[], int, int);

int main(int argc, char * argv[]) {
    int c;
    int nlines; // 读入的输入行数
    int numeric = 0;    // 若进行数值排序，则numeric的值为1
    int reverse = 0;    // 若要逆序排列，则reverse的值为1

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    break;
            }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        // (void **)强制类型转换
        my_qsort((void **)lineptr, 0, nlines-1, reverse, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        c = getchar();
        return 0;
    } else {
        printf("input too big to sort\n");
        c = getchar();
        return 1;
    }
}

void my_qsort(void *v[], int left, int right, int r, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)  // 元素个数小于2，则不执行任何操作
        return;
    swap(v, left, (left + right)/2);
    last = left;
    if (!r) {
        for (i = left+1; i <= right; i++)
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        swap(v, left, last);
        my_qsort(v, left, last-1, r, comp);
        my_qsort(v, last+1, right, r, comp);
    } else {
        for (i = left+1; i <= right; i++)
            if ((*comp)(v[i], v[left]) > 0)
                swap(v, ++last, i);
        swap(v, left, last);
        my_qsort(v, left, last-1, r, comp);
        my_qsort(v, last+1, right, r, comp);
    }
}

int numcmp(char *s1, char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getline(char *s, int lim) {
    int i, c;
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    // 保留换行符
    // s[i++] = '\n';
    s[i] = '\n';
    return i;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len)) == NULL)
            return -1;
        else {
            line[len] = '\0'; //删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i=0; i < nlines; i++)
        // 添加换行符
        printf("%s\n", lineptr[i]);
}