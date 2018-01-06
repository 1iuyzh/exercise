#include"BinaryHeap.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int tmp;
    vector<int> v = {13, 21, 16, 24, 32, 19, 68, 65, 26, 31};
    BinaryHeap<int> heap(v);
    heap.printHeap();
    heap.insert(14);
    heap.printHeap();
    heap.deleteMin(tmp);
    heap.printHeap();

    BinaryHeap<int> heap2;
    for (auto &i : v)
        heap2.insert(i);
    heap2.printHeap();
    heap2.insert(14);
    heap2.printHeap();
    heap2.deleteMin(tmp);
    heap2.printHeap();

    return 0;
}