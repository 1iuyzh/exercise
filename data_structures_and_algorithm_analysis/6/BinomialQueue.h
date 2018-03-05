#ifndef BINOMIAL_QUEUE_H
#define BINOMIAL_QUEUE_H

#include<iostream>
#include<vector>
using namespace std;

template <typename Comparable>
class BinomialQueue {
public:
    BinomialQueue();
    BinomialQueue(const Comparable &item);
    BinomialQueue(const BinomialQueue &rhs);
    BinomialQueue(BinomialQueue &&rhs);
    
    ~BinomialQueue();

    BinomialQueue& operator=(const BinomialQueue &rhs);
    BinomialQueue& operator=(BinomialQueue &&rhs);

    bool isEmpty();
    const Comparable& findMin() const;

    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void deleteMin();
    void deleteMin(Comparable &minItem);

    void makeEmpty();
    void merge(BinomialQueue &rhs);

    // void printQueue(ostream &out = cout) const;

private:
    struct BinomialNode {
        Comparable element;
        BinomialNode *rightChild;
        BinomialNode *nextSibling;

        BinomialNode(const Comparable &e, BinomialNode *rt, BinomialNode *st)
            : element(e), rightChild(rt), nextSibling(st) {}
        BinomialNode(Comparable &&e, BinomialNode *rt, BinomialNode *st)
            : element(e), rightChild(rt), nextSibling(st) {}
    };

    const static int DEFAULT_TREES = 1;

    vector<BinomialNode *> theTrees;    // 树根组成的数组
    int currentSize;    // 优先队列中的项数

    int findMinIndex() const;
    int capacity() const;
    BinomialNode *combineTrees(BinomialNode *t1, BinomialNode *t2);
    void makeEmpty(BinomialNode * &t);
    BinomialNode *clone(BinomialNode *t) const;
    // void printTree(ostream &out, BinomialNode *t, int depth = 0) const;
};

/*
template <typename Comparable>
void BinomialQueue<Comparable>::printQueue(ostream &out) const {
    if (isEmpty())
        return;
    for (auto &tree : theTrees)
        printTree(out, tree, 0);
}

template <typename Comparable>
void BinomialQueue<Comparable>::printTree(ostream &out, BinaryNode *t, int depth) const {
    if (t == nullptr)
        return;
    else if (t->rightChild == nullptr && t->nextSibling == nullptr) {
        for (int i = 0; i < depth; i++)
            out << ' ';
        out << t->element << endl;
    }
    else {
        for (int i = 0; i < depth; i++)
            out << ' ';
        out << t->element << endl;
        printTree(out, t->nextSibling, depth + 1);
        printTree(out, t->rightChild, depth + 1);
    }
}
*/

// DEFAULT_TREES
template <typename Comparable>
BinomialQueue<Comparable>::BinomialQueue() : theTrees(DEFAULT_TREES, nullptr), currentSize(0) {}

template <typename Comparable>
BinomialQueue<Comparable>::BinomialQueue(const Comparable &item) : theTrees{nullptr}, currentSize(0) {
    theTrees[0] = new BinomialNode(item, nullptr, nullptr);
    ++currentSize;
}

template <typename Comparable>
BinomialQueue<Comparable>::BinomialQueue(const BinomialQueue &rhs) : theTrees{nullptr}, currentSize(0) {
    theTrees.resize(rhs.theTrees.size());
    for (int i = 0; i < theTrees.size(); ++i)
        theTrees[i] = clone(rhs.theTrees[i]);
    currentSize = rhs.currentSize;
}

template <typename Comparable>
BinomialQueue<Comparable>::BinomialQueue(BinomialQueue &&rhs) : theTrees{nullptr}, currentSize(0) {
    theTrees.resize(rhs.theTrees.size());
    for (int i = 0; i < theTrees.size(); ++i) {
        theTrees[i] = rhs.theTrees[i];
        rhs.theTrees[i] = nullptr;
    }
    currentSize = rhs.currentSize;
    rhs.currentSize = 0;
}

template <typename Comparable>
BinomialQueue<Comparable>::~BinomialQueue() {
    makeEmpty();
}

template <typename Comparable>
BinomialQueue<Comparable>& BinomialQueue<Comparable>::operator=(const BinomialQueue &rhs) {
    makeEmpty();
    theTrees.resize(rhs.theTrees.size());
    for (int i = 0; i < theTrees.size(); ++i)
        theTrees[i] = clone(rhs.theTrees[i]);
    currentSize = rhs.currentSize;
}

template <typename Comparable>
BinomialQueue<Comparable>& BinomialQueue<Comparable>::operator=(BinomialQueue &&rhs) {
    makeEmpty();
    theTrees.resize(rhs.theTrees.size());
    for (int i = 0; i < theTrees.size(); ++i) {
        theTrees[i] = rhs.theTrees[i];
        rhs.theTrees[i] = nullptr;
    }
    currentSize = rhs.currentSize;
    rhs.currentSize = 0;
}

template <typename Comparable>
bool BinomialQueue<Comparable>::isEmpty() {
    return currentSize == 0 ? true : false;
}

template <typename Comparable>
const Comparable& BinomialQueue<Comparable>::findMin() const {
    int minIndex = findMinIndex();
    return theTrees[minIndex]->element;
}

template <typename Comparable>
void BinomialQueue<Comparable>::insert(const Comparable &x) {
    BinomialQueue bq(x);
    merge(bq);
}

template <typename Comparable>
void BinomialQueue<Comparable>::insert(Comparable &&x) {
    Comparable x1(x);
    BinomialQueue bq(x1);
    merge(bq);
}

template <typename Comparable>
void BinomialQueue<Comparable>::makeEmpty() {
    if (isEmpty())
        return;
    for (auto &x : theTrees)
        makeEmpty(x);
    currentSize = 0;
}

template <typename Comparable>
typename BinomialQueue<Comparable>::BinomialNode *BinomialQueue<Comparable>::combineTrees(BinomialNode *t1, BinomialNode *t2) {
    if (t1->element < t2->element)
        return combineTrees(t2, t1);
    t2->nextSibling = t1->rightChild;
    t1->rightChild = t2;
    return t1;
}

template <typename Comparable>
void BinomialQueue<Comparable>::merge(BinomialQueue &rhs) {
    if (this == &rhs)   // 避免别名
        return;
    
    currentSize += rhs.currentSize;

    if (currentSize > capacity()) {
        int oldNumTrees = theTrees.size();
        int newNumTrees = max(theTrees.size(), rhs.theTrees.size()) + 1;
        theTrees.resize(newNumTrees);
        for (int i = oldNumTrees; i < newNumTrees; ++i)
            theTrees[i] = nullptr;
    }

    BinomialNode *carry = nullptr;

    for (int i = 0, j = 1; j <= currentSize; ++i, j*=2) {
        BinomialNode *t1 = theTrees[i];
        BinomialNode *t2 = i < rhs.theTrees.size() ? rhs.theTrees[i] : nullptr;

        // 状态机?
        int whichCase = (t1 == nullptr) ? 0 : 1;
        whichCase += (t2 == nullptr) ? 0 : 2;
        whichCase += (carry == nullptr) ? 0 : 4;

        switch (whichCase) {
            case 0: // empty
            case 1: // this
                break;
            case 2: // rhs
                theTrees[i] = t2;
                rhs.theTrees[i] = nullptr;
                break;
            case 4: // carry
                theTrees[i] = carry;
                carry = nullptr;
                break;
            case 3: // this and rhs
                carry = combineTrees(t1, t2);
                theTrees[i] = nullptr;
                rhs.theTrees[i] = nullptr;
                break;
            case 5: // this and carry
                carry = combineTrees(t1, carry);
                theTrees[i] = nullptr;
                break;
            case 6: // rhs and carry
                carry = combineTrees(t2, carry);
                rhs.theTrees[i] = nullptr;
                break;
            case 7: // all
                theTrees[i] = carry;
                carry = combineTrees(t1, t2);
                rhs.theTrees[i] = nullptr;
                break;
        }
    }

    for (auto &root : rhs.theTrees)
        root = nullptr;
    rhs.currentSize = 0;
}

template <typename Comparable>
void BinomialQueue<Comparable>::deleteMin() {
    Comparable minItem;
    deleteMin(minItem);
}

template <typename Comparable>
void BinomialQueue<Comparable>::deleteMin(Comparable &minItem) {
    if (isEmpty())
        //throw UnderflowException();
        return;
    int minIndex = findMinIndex();
    minItem = theTrees[minIndex]->element;

    BinomialNode *oldRoot = theTrees[minIndex];
    BinomialNode *deletedTree = oldRoot->rightChild;

    delete oldRoot; // 删除*theTrees[minIndex]

    BinomialQueue deletedQueue;
    deletedQueue.theTrees.resize(minIndex + 1);
    deletedQueue.currentSize = (1 << minIndex) - 1;
    for (int j = minIndex - 1; j >= 0; --j) {
        deletedQueue.theTrees[j] = deletedTree;
        deletedTree = deletedTree->nextSibling;
        deletedQueue.theTrees[j]->nextSibling = nullptr;
    }

    theTrees[minIndex] = nullptr;
    currentSize -= deletedQueue.currentSize + 1; // deleteMin()删除了一个

    merge(deletedQueue);
}

template <typename Comparable>
int BinomialQueue<Comparable>::findMinIndex() const {
    if (isEmpty())
        return -1;
    int i;
    int minIndex;

    for (i = 0; theTrees[i] == nullptr; ++i);

    for (minIndex = i; i < theTrees.size(); ++i)
        if (theTrees[i] != nullptr && theTrees[i]->element < theTrees[minIndex]->element)
            minIndex = i;
    
    return minIndex;
}

template <typename Comparable>
int BinomialQueue<Comparable>::capacity() const {
    return (1 << theTrees.size()) - 1;
}

template <typename Comparable>
void BinomialQueue<Comparable>::makeEmpty(BinomialNode * &t) {
    if (t != nullptr) {
        makeEmpty(t->nextSibling);
        makeEmpty(t->rightChild);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
typename BinomialQueue<Comparable>::BinomialNode *BinomialQueue<Comparable>::clone(BinomialNode *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new BinomialNode(t->element, clone(t->rightChild), clone(t->nextSibling));
}

#endif