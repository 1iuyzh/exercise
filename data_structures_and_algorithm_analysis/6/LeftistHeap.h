#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H

#include<iostream>
using namespace std;

template <typename Comparable>
class LeftistHeap {
public:
    LeftistHeap();
    LeftistHeap(const LeftistHeap &rhs);
    LeftistHeap(LeftistHeap &&rhs);
    
    ~LeftistHeap();

    LeftistHeap & operator=(const LeftistHeap &rhs);
    LeftistHeap & operator=(LeftistHeap &&rhs);

    bool isEmpty() const;
    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void deleteMin();
    void makeEmpty();
    void merge(LeftistHeap &rhs);
    void printHeap(ostream &out = cout) const;

private:
    struct LeftistNode {
        Comparable element;
        LeftistNode *left;
        LeftistNode *right;
        int npl;

        LeftistNode(const Comparable &e, LeftistNode *lt = nullptr, LeftistNode *rt = nullptr, int np = 0)
            : element(e), left(lt), right(rt), npl(np) {}
        LeftistNode(Comparable &&e, LeftistNode *lt = nullptr, LeftistNode *rt = nullptr, int np = 0)
            : element(std::move(e)), left(lt), right(rt), npl(np) {}
    };

    LeftistNode *root;

    LeftistNode *merge(LeftistNode *h1, LeftistNode *h2);
    LeftistNode *merge1(LeftistNode *h1, LeftistNode *h2);

    LeftistNode *clone(LeftistNode *t) const;;
    void makeEmpty(LeftistNode * &t);
    void swapChildren(LeftistNode *t)
    void printHeap(ostream &out, LeftistNode *t, int depth = 0) const;
};

template <typename Comparable>
LeftistHeap<Comparable>::LeftistHeap() {
    root = nullptr;
}

template <typename Comparable>
LeftistHeap<Comparable>::~LeftistHeap() {
    makeEmpty();
}

template <typename Comparable>
void LeftistHeap<Comparable>::makeEmpty() {
    makeEmpty(root);
}

template <typename Comparable>
void LeftistHeap<Comparable>::makeEmpty(LeftistNode * &t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
LeftistHeap<Comparable>::LeftistHeap(const LeftistHeap &rhs) {
    root = clone(rhs.root);
}

template <typename Comparable>
LeftistHeap<Comparable>::LeftistHeap(LeftistHeap &&rhs) {
    root = rhs.root;
    rhs.root = nullptr;
    // std::move()仅仅是一个声明, 用以说明不会调用该对象的值
    // 可以在类内修改同类对象成员的值
}

template <typename Comparable>
typename LeftistHeap<Comparable>::LeftistNode *LeftistHeap<Comparable>::clone(LeftistNode *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new LeftistNode(t->element, clone(t->left), clone(t->right));
}

template <typename Comparable>
LeftistHeap<Comparable>& LeftistHeap<Comparable>::operator=(const LeftistHeap &rhs) {
    root = clone(rhs.root);
}

template <typename Comparable>
LeftistHeap<Comparable>& LeftistHeap<Comparable>::operator=(LeftistHeap &&rhs) {
    root = rhs.root;
    rhs.root = nullptr;
}

template <typename Comparable>
void LeftistHeap<Comparable>::merge(LeftistHeap &rhs) {
    if (this == &rhs)
        return; // 避免别名
    root = merge(root, rhs.root);
    rhs.root = nullptr;
}

template <typename Comparable>
typename LeftistHeap<Comparable>::LeftistNode * LeftistHeap<Comparable>::merge(LeftistNode *h1, LeftistNode *h2) {
    if (h1 == nullptr)
        return h2;
    if (h2 == nullptr)
        return h1;
    if (h1->element < h2->element)
        return merge1(h1, h2);
    else
        return merge1(h2, h1);
}

template <typename Comparable>
typename LeftistHeap<Comparable>::LeftistNode * LeftistHeap<Comparable>::merge1(LeftistNode *h1, LeftistNode *h2) {
    if (h1->left == nullptr)
        h1->left = h2;
    else {
        h1->right = merge(h1->right, h2);
        if (h1->left->npl < h1->right->npl)
            swapChildren(h1);
        h1->npl = h1->right->npl + 1; // 更新npl
    }
    return h1;
}

template <typename Comparable>
void LeftistHeap<Comparable>::swapChildren(LeftistNode *t) {
    swap(t->left, t->right);
}

template <typename Comparable>
void LeftistHeap<Comparable>::insert(const Comparable &x) {
    root = merge(new LeftistNode{x}, root);
}

template <typename Comparable>
void LeftistHeap<Comparable>::printHeap(ostream &out) const {
    printHeap(out, root, 0);
}

template <typename Comparable>
void LeftistHeap<Comparable>::printHeap(ostream &out, LeftistNode *t, int depth) const {
    if (t == nullptr)
        return;
    else if (t->left == nullptr && t->right == nullptr) {
        for (int i = 0; i < depth; i++)
            out << ' ';
        out << t->element << ' ' << t->npl << endl;
    }
    else {
        for (int i = 0; i < depth; i++)
            out << ' ';
        out << t->element << ' ' << t->npl << endl;
        printHeap(out, t->left, depth + 1);
        printHeap(out, t->right, depth + 1);
    }
}

template <typename Comparable>
bool LeftistHeap<Comparable>::isEmpty() const {
    return root == nullptr ? true : false;
}

template <typename Comparable>
void LeftistHeap<Comparable>::deleteMin() {
    if (isEmpty())
        return;
    LeftistNode *oldRoot = root;
    root = merge(root->left, root->right);
    delete oldRoot;
}

#endif