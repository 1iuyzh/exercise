#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include<iostream>
using namespace std;

template <typename Comparable>
class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree &rhs);
    BinarySearchTree(BinarySearchTree &&lhs);
    ~BinarySearchTree();

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const;
    bool isEmpty() const;
    void printTree(ostream &out = cout) const;

    void makeEmpty();
    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void remove(const Comparable &x);

    BinarySearchTree& operator=(const BinarySearchTree &rhs);
    BinarySearchTree& operator=(BinarySearchTree &&lhs);

private:
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode &rt)
            : element(theElement), left(lt), right(rt) { }
        BinaryNode(Comparable &&theElement, BinaryNode *lt, BinaryNode *rt)
            : element(std::move(theElement)), left(lt), right(rt) { }
    };
    
    BinaryNode *root;

    void insert(const Comparable &x, BinaryNode * &t);
    void insert(Comparable &&x, BinaryNode * &t);
    void remove(const Comparable &x, BinaryNode * &t);
    BinaryNode *findMax(BinaryNode *t) const;
    BinaryNode *findMin(BinaryNode *t) const;
    bool contains(const Comparable &x, BinaryNode *t) const;
    void makeEmpty(BinaryNode * &t);
    void printTree(BinaryNode *t, ostream &out) const;
    BinaryNode *clone(BinaryNode *t) const;
};

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() {
    root = nullptr;
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree &rhs) : root(nullptr) {
    root = clone(rhs.root);
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree &&lhs) : root(nullptr) {
    root = lhs.root;
    lhs.root = nullptr; // check
}

template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree() {
    makeEmpty();
}

template <typename Comparable>
const Comparable &BinarySearchTree<Comparable>::findMin() const {
    return findMin(root)->element;
}

template <typename Comparable>
const Comparable &BinarySearchTree<Comparable>::findMax() const {
    return findMax(root)->element;
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x) const {
    return contains(x, root);
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const {
    if (root == nullptr)
        return true;
    else
        return false;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(ostream &out) const {
    printTree(root, out);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x) {
    insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable &&x) {
    insert(std::move(x), root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x) {
    remove(x, root);
}

template <typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree &rhs) {
    root = clone(rhs.root);
}

template <typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(BinarySearchTree &&lhs) {
    root = lhs.root;
    lhs.root = nullptr;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable &x, BinaryNode * &t) {
    if (t == nullptr)
        t = new BinaryNode(x, nullptr, nullptr);    // 创建new所以需要传引用调用
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
    else
        return;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable &&x, BinaryNode * &t) {
    if (t == nullptr)
        t = new BinaryNode(std::move(x), nullptr, nullptr);
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (t->element < x)
        insert(std::move(x), t->right);
    else
        return;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable &x, BinaryNode * &t) {
    if (t == nullptr)
        return;
    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr) {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else {
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMin(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::findMax(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    if (t->right == nullptr)
        return t;
    return findMax(t->right);
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x, BinaryNode *t) const {
    if (t == nullptr)
        return false;
    else if (x < t->element)
        return contains(x, t->left);
    else if (t->element < x)
        return contains(x, t->right);
    else
        return true;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode * &t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode *t, ostream &out) const {
    if (t == nullptr)
        return;
    else if (t->left == nullptr && t->right == nullptr)
        out << t->element << endl;
    else {
        out << t->element << endl;
        out << '\t';
        printTree(t->left);
        printTree(t->right);
    }        
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *BinarySearchTree<Comparable>::clone(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new BinaryNode(t->element, clone(t->left), clone(t->right));
}

#endif