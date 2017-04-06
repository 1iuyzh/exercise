#include <stdio.h>
#include <stdlib.h> // 随机数函数srand(), rand()
#include <time.h> // 返回当前时间time()
#include <limits.h> // int类型的最大值INT_MAX

#define N 50000

int s[N];

// 产生随机数数组
void rand_init(void) {
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        s[i] = rand()%INT_MAX;
}

void my_swap(int s[], int i, int j) {
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void my_qsort(int s[], int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    my_swap(s, left, mid);
    int j = left + 1;
    for (int i = j; i <= right; i++) {
        if (s[i] < s[left]) {
            my_swap(s, i, j);
            j++;
        }
    }
    mid = j-1;
    my_swap(s, left, mid);
    my_qsort(s, left, mid-1);
    my_qsort(s, mid+1, right);
}

void my_bubble(int s[], int max) {
    for (int i = 0; i < max; i++) {
        for (int j = i + 1; j <= max; j++) {
            if (s[j] < s[i])
                my_swap(s, i, j);
        }
    }
}

int main(void) {
    clock_t time_begin, time_end;
    rand_init();
    time_begin = clock();
    my_qsort(s, 0, N-1);
    time_end = clock();
    printf("the time of qsort is %d ms\n", time_end-time_begin);
    rand_init();
    time_begin = clock();
    my_bubble(s, N-1);
    time_end = clock();
    printf("the time of bubble sort is %d ms\n", time_end-time_begin);
    return 0;
}