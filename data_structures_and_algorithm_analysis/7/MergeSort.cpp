#include<iostream>
#include<vector>
using namespace std;

// time:  O(NlogN)
// space: O(N)
template <typename Comparable>
void mergeSort(vector<Comparable>&);
template <typename Comparable>
void mergeSort(vector<Comparable>&, vector<Comparable>&, int, int);
template <typename Comparable>
void merge(vector<Comparable>&, vector<Comparable>&, int, int, int);

template <typename Comparable>
void mergeSort(vector<Comparable> &a) {
    vector<Comparable> tmp(a.size());
    mergeSort(a, tmp, 0, a.size()-1);
}

template <typename Comparable>
void mergeSort(vector<Comparable> &a, vector<Comparable> &tmp, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center+1, right);
        merge(a, tmp, left, center, right);
    }
}

template <typename Comparable>
void merge(vector<Comparable> &a, vector<Comparable> &tmp, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;

    while (leftPos <= leftEnd && rightPos <= rightEnd) {
        if (a[leftPos] < a[rightPos])
            tmp[tmpPos++] = std::move(a[leftPos++]);
        else
            tmp[tmpPos++] = std::move(a[rightPos++]);
    }

    while (leftPos <= leftEnd)
        tmp[tmpPos++] = std::move(a[leftPos++]);

    while (rightPos <= rightEnd)
        tmp[tmpPos++] = std::move(a[rightPos++]);

    while (rightEnd >= 0)
        a[rightEnd] = std::move(tmp[rightEnd--]);
}

int main() {
    vector<int> a{31, 41, 59, 26, 53, 58, 97};
    mergeSort(a);
    for (auto &i : a)
        cout << i << ' ';
    return 0;
}