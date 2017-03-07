#include <stdio.h>
#define MAXLEN 10000

void qsort(int [], int, int);
void swap(int [], int, int);

int main(void) {
    int c;
    int v[MAXLEN];
    for (c=0; c<MAXLEN; c++)
        v[c] = MAXLEN - c;
    qsort(v, 0, MAXLEN-1);
    for (c=0; c<MAXLEN; c++)
        printf("%d\n", v[c]);
    c = getchar();
    return 0;
}

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right) {
    int last, i;
    if (left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for (i=left+1; i<=right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
