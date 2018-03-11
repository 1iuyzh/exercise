#include<iostream>
#include<vector>
using namespace std;

// time:  O(N2)
// space: O(1)
template <typename Comparable>
void insertionSort(vector<Comparable> &a) {
    for (int i = 1; i < a.size(); ++i) {
        Comparable tmp = std::move(a[i]);
        int j = 0;
        for (j = i-1; j >= 0 && tmp < a[j]; --j)
            a[j+1] = std::move(a[j]);
        a[j+1] = std::move(tmp);
    }
}

int main() {
    vector<int> a{ 34, 8, 64, 51, 32, 21 };
    insertionSort(a);
    for (auto &i : a)
        cout << i << ' ';
    return 0;
}