#include <stdio.h>
#include <stdlib.h> // 随机函数srand(), rand()
#include <time.h> // 返回当前时间time()
#include <limits.h> // INT_MAX

#define MaxNum 10000000

int n[MaxNum];

// 产生随机数数组
void rand_init(void) {
    srand(time(NULL));
    for (int i = 0; i < MaxNum; i++)
        n[i] = rand()%41 - 20; // -20到20的整数
}

// 算法1, O(N3)
int MaxSubsequenceSum1(const int A[], int N) {
    int ThisSum, MaxSum, i, j, k;
    MaxSum = 0;
    for (i = 0; i < N; i++)
        for (j = i; j < N; j++) {
            ThisSum = 0;
            for (k = i; k <= j; k++)
                ThisSum += A[k];
                if (ThisSum > MaxSum)
                    MaxSum = ThisSum;
        }
    return MaxSum;
}

// 算法2, O(N2)
int MaxSubsequenceSum2(const int A[], int N) {
    int ThisSum, MaxSum, i, j;
    MaxSum = 0;
    for (i = 0; i < N; i++) {
        ThisSum = 0;
        for (j = i; j < N; j++) {
            ThisSum += A[j];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

int Max3(int n1, int n2, int n3) {
    if (n1 >= n2 && n1 >= n3)
        return n1;
    if (n2 >= n1 && n2 >= n3)
        return n2;
    if (n3 >= n1 && n3 >= n2)
        return n3;
}

// 算法3, 分治策略, O(NlogN)
static int MaxSubSum(const int A[], int Left, int Right) {
    int MaxLeftSum, MaxRightSum;
    int MaxLeftBorderSum, MaxRightBorderSum;
    int LeftBorderSum, RightBorderSum;
    int Center, i;

    if (Left == Right)
        if (A[Left] > 0)
            return A[Left];
        else
            return 0;
    
    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);

    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = Center; i >= Left; i--) {
        LeftBorderSum += A[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = Center + 1; i<= Right; i++) {
        RightBorderSum += A[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum3(const int A[], int N) {
    return MaxSubSum(A, 0, N - 1);
}

// 算法4, O(N)
int MaxSubsequenceSum4(const int A[], int N) {
    int ThisSum, MaxSum, j;
    ThisSum = MaxSum = 0;
    for (j = 0; j < N; j++) {
        ThisSum += A[j];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main(void) {
    clock_t time_begin, time_end;
    rand_init();
    /*
    time_begin = clock();
    printf("the result of MaxSubsequenceSum1 is %d\n", MaxSubsequenceSum1(n, MaxNum));
    time_end = clock();
    printf("the time of MaxSubsequenceSum1 is %d ms\n", time_end - time_begin);
    time_begin = clock();
    printf("the result of MaxSubsequenceSum2 is %d\n", MaxSubsequenceSum2(n, MaxNum));
    time_end = clock();
    printf("the time of MaxSubsequenceSum2 is %d ms\n", time_end - time_begin);
    */
    time_begin = clock();
    printf("the result of MaxSubsequenceSum3 is %d\n", MaxSubsequenceSum3(n, MaxNum));
    time_end = clock();
    printf("the time of MaxSubsequenceSum3 is %d ms\n", time_end - time_begin);
    time_begin = clock();
    printf("the result of MaxSubsequenceSum4 is %d\n", MaxSubsequenceSum4(n, MaxNum));
    time_end = clock();
    printf("the time of MaxSubsequenceSum4 is %d ms\n", time_end - time_begin);
    return 0;
}