#include <stdio.h>
#include <time.h>
#define MAX 20000
int binsearch(int x, int v[], int n);
int search(int x, int v[], int n);

int main()
{
    int testdata[MAX];
    int index;
    int n = 0;
    int i, c;
    clock_t time_taken;
    /* Initialization */
    for (i=0; i<MAX; i++)
        testdata[i] = i;
    /* binsearch */
    for (i=0, time_taken=clock(); i<100000; i++)
        index = binsearch(n, testdata, MAX);
    time_taken = clock() - time_taken;
    if (index < 0)
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);
    printf("binsearch() took %lu clocks (%lu seconds).\n", (unsigned long) time_taken, (unsigned long) time_taken/CLOCKS_PER_SEC);
    /* search */
    for (i=0, time_taken=clock(); i<100000; i++)
        index = search(n, testdata, MAX);
    time_taken = clock() - time_taken;
    if (index < 0)
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);
    printf("search took %lu clocks (%lu seconds).\n", (unsigned long) time_taken, (unsigned long) time_taken/CLOCKS_PER_SEC);
    c = getchar();
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n-1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int search(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n-1;
    mid = (low + high) / 2;
    while (low <= high && v[mid] != x)
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else 
        return -1;
}
