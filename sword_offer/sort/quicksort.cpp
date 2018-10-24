#include <iostream>
#include <vector>

void QuickSort(std::vector<int> &a, int left, int right) {
    if (left == right)
        return;
    
    if (right - left == 1) {
        if (a[right] < a[left])
            std::swap(a[left], a[right]);
        return;
    }
    
    int center = (left + right) / 2;
    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);
    
    std::swap(a[center], a[right-1]);
    int i = left, j = right - 1;
    while (i < j) {
        while (a[++i] < a[right-1]);
        while (a[--j] > a[right-1]);
        if (i < j)
            std::swap(a[i], a[j]);
    }
    std::swap(a[i], a[right-1]);
    QuickSort(a, left, i-1);
    QuickSort(a, i+1, right);
}

void QuickSort(std::vector<int> &a) {
    QuickSort(a, 0, a.size()-1);
}

int main() {
    std::vector<int> a{34, 8, 64, 51, 32, 21, 34, 8, 64, 51, 32, 21, 34, 8, 64, 51, 32, 21};
    QuickSort(a);
    for (auto &i : a)
        std::cout << i << ' ';
    return 0;
}