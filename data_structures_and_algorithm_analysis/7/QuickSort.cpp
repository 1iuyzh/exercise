#include<iostream>
#include<vector>
using namespace std;

template <typename Comparable>
void quickSort(vector<Comparable>&, int, int);

template <typename Comparable>
void quickSort(vector<Comparable> &a) {
    quickSort(a, 0, a.size()-1);
}

template <typename Comparable>
void insertionSort(vector<Comparable> &a, int left, int right) {
    for (int i = left+1; i <= right; ++i) {
        Comparable tmp = std::move(a[i]);
        int j = 0;
        for (j = i-1; j >= 0 && tmp < a[j]; --j)
            a[j+1] = std::move(a[j]);
        a[j+1] = std::move(tmp);
    }
}

template <typename Comparable>
void quickSort(vector<Comparable> &a, int left, int right) {
    if (right - left >= 10) {
        int center = (left + right) / 2;
        if (a[center] < a[left]) swap(a[left], a[center]);
        if (a[right] < a[left]) swap(a[left], a[right]);
        if (a[right] < a[center]) swap(a[center], a[right]);
        swap(a[center], a[right-1]);
        // int pivot = a[right-1];
        int i = left, j = right - 1;
        while (i < j) {
            while (a[++i] < a[right-1]);
            while (a[--j] > a[right-1]);
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[i], a[right-1]);
        quickSort(a, left, i-1);
        quickSort(a, i+1, right);
    }
    else
        insertionSort(a, left, right);
}

int main() {
    vector<int> a{34, 8, 64, 51, 32, 21, 34, 8, 64, 51, 32, 21, 34, 8, 64, 51, 32, 21};
    quickSort(a);
    for (auto &i : a)
        cout << i << ' ';
    return 0;
}