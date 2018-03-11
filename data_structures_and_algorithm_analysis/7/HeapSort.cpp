#include<iostream>
#include<vector>
using namespace std;

// time:  最坏运行时间O(NlogN)
// space: O(1)
template <typename Comparable>
void percDown(vector<Comparable> &a, int i, int n) {
    int child = 2 * i + 1;
    if (child != n-1 && a[child] < a[child+1])
        ++child;
    if (child < n && a[i] < a[child]) {
        swap(a[i], a[child]);
        percDown(a, child, n);
    }
}

template <typename Comparable>
void heapSort(vector<Comparable> &a) {
    for (int i = a.size()/2-1; i >= 0; --i)
        percDown(a, i, a.size());
    for (int i = a.size()-1; i > 0; --i) {
        swap(a[0], a[i]);
        percDown(a, 0, i);
    }
}

int main() {
    vector<int> a{31, 41, 59, 26, 53, 58, 97};
    heapSort(a);
    for (auto &i : a)
        cout << i << ' ';
    return 0;
}