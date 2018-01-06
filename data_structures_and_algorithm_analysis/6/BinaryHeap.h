#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include<iostream>
#include<vector>
using namespace std;

template <typename Comparable>
class BinaryHeap {
public:
    explicit BinaryHeap(int capacity = 100);
    explicit BinaryHeap(const vector<Comparable> &items);

    bool isEmpty() const;
    //const Comparable &findMax() const;

    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void deleteMin();
    void deleteMin(Comparable &minItem);
    void makeEmpty();

    void printHeap() const;

private:
    int currentSize;
    vector<Comparable> array;

    void buildHeap();
    void percolateDown(int hole);
};

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity) : array(capacity), currentSize(0) { }

template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable> &items)
    : array(items.size() + 10), currentSize(items.size()) {
    for (int i = 0; i < items.size(); i++)
        array[i+1] = items[i];
    buildHeap();
}

template <typename Comparable>
bool BinaryHeap<Comparable>::isEmpty() const {
    return currentSize == 0 ? true : false;
}

template <typename Comparable>
void BinaryHeap<Comparable>::makeEmpty() {
    currentSize = 0;
}

template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x) {
    if (currentSize == array.size() - 1)
        array.resize(array.size() * 2);
    //percolate up
    int hole = ++currentSize;
    Comparable copy = x;

    array[0] = std::move(copy);
    for (; x < array[hole/2]; hole /= 2)
        array[hole] = std::move(array[hole/2]);
    array[hole] = std::move(array[0]);
}

template <typename Comparable>
void BinaryHeap<Comparable>::insert(Comparable &&x) {
    if (currentSize == array.size() - 1)
        array.resize(array.size() * 2);
    //percolate up
    int hole = ++currentSize;

    array[0] = std::move(x);
    for (; array[0] < array[hole/2]; hole /= 2)
        array[hole] = std::move(array[hole/2]);
    array[hole] = std::move(array[0]);
}

// 删除最小项
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin() {
    if (isEmpty())
        return;
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
}

// 删除最小项并将其放在minItem处
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable &minItem) {
    if (isEmpty())
        return;
    minItem = std::move(array[1]);
    array[1] = std::move(array[currentSize--]);
    percolateDown(1);
}

// 在堆内进行下滤的内部方法
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole) {
    int child;
    Comparable tmp = std::move(array[hole]);

    for (; hole * 2 <= currentSize; hole = child) {
        child = hole * 2;
        if (child != currentSize && array[child+1] < array[child])
            ++child;
        if (array[child] < tmp)
            array[hole] = std::move(array[child]);
        else
            break;
    }
    array[hole] = std::move(tmp);
}

template <typename Comparable>
void BinaryHeap<Comparable>::printHeap() const {
    for (int i = 1; i <= currentSize; i++)
        cout << array[i] << ' ';
    cout << endl;
}

template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap() {
    for (int i = currentSize / 2; i > 0; --i)
        percolateDown(i);
}

#endif