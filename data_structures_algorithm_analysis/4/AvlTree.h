#ifndef AVLTREE_H
#define AVLTREE_H

#include<iostream>
using namespace std;

static const int ALLOWED_IMBALANCE = 1;

template <typename Comparable>
class AvlTree {
public:
    AvlTree();
    AvlTree(const AvlTree &rhs);
    AvlTree(AvlTree &&lhs);
    ~AvlTree();

    const Comparable &findMin() const;
    const Comparable &findMax() const;
    bool contains(const Comparable &x) const;
    bool isEmpty() const;
    void printTree(ostream &out = cout) const;

    void makeEmpty();
    void insert(const Comparable &x);
    void insert(Comparable &&x);
    void remove(const Comparable &x);

    AvlTree& operator=(const AvlTree &rhs);
    AvlTree& operator=(AvlTree &&lhs);

private:
    struct AvlNode {
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;

        AvlNode(const Comparable &theElement, AvlNode *lt, AvlNode *rt)
            : element(theElement), left(lt), right(rt) { }
        AvlNode(Comparable &&theElement, AvlNode *lt, AvlNode *rt)
            : element(std::move(theElement)), left(lt), right(rt) { }
    };
    
    AvlNode *root;

    int height(AvlNode *t) const;
    void insert(const Comparable &x, AvlNode * &t);
    void insert(Comparable &&x, AvlNode * &t);
    void remove(const Comparable &x, AvlNode * &t);
    void balance(AvlNode * &t);
    void rotateWithLeftChild(AvlNode * &k2);
    void rotateWithRightChild(AvlNode * &k1);
    void doubleWithLeftChild(AvlNode * &k3);
    void doubleWithRightChild(AvlNode * &k3);
    AvlNode *findMax(AvlNode *t) const;
    AvlNode *findMin(AvlNode *t) const;
    bool contains(const Comparable &x, AvlNode *t) const;
    void makeEmpty(AvlNode * &t);
    void printTree(ostream &out, AvlNode *t, int depth = 0) const;
    AvlNode *clone(AvlNode *t) const;
};

template <typename Comparable>
AvlTree<Comparable>::AvlTree() {
    root = nullptr;
}

template <typename Comparable>
AvlTree<Comparable>::AvlTree(const AvlTree &rhs) : root(nullptr) {
    root = clone(rhs.root);
}

template <typename Comparable>
AvlTree<Comparable>::AvlTree(AvlTree &&lhs) : root(nullptr) {
    root = lhs.root;
    lhs.root = nullptr; //check
}

template <typename Comparable>
AvlTree<Comparable>::~AvlTree() {
    makeEmpty();
}

template <typename Comparable>
const Comparable &AvlTree<Comparable>::findMin() const {
    return findMin(root)->element;
}

template <typename Comparable>
const Comparable &AvlTree<Comparable>::findMax() const {
    return findMax(root)->element;
}

template <typename Comparable>
bool AvlTree<Comparable>::contains(const Comparable &x) const {
    return contains(x, root);
}

template <typename Comparable>
bool AvlTree<Comparable>::isEmpty() const {
    if (root == nullptr)
        return true;
    else
        return false;
}

template <typename Comparable>
void AvlTree<Comparable>::printTree(ostream &out) const {
    printTree(out, root, 0);
}

template <typename Comparable>
void AvlTree<Comparable>::makeEmpty() {
    makeEmpty(root);
}

template <typename Comparable>
int AvlTree<Comparable>::height(AvlNode *t) const {
    return t == nullptr ? -1 : t->height;
}

template <typename Comparable>
void AvlTree<Comparable>::insert(const Comparable &x) {
    insert(x, root);
}

template <typename Comparable>
void AvlTree<Comparable>::insert(Comparable &&x) {
    insert(std::move(x), root);
}

template <typename Comparable>
void AvlTree<Comparable>::remove(const Comparable &x) {
    remove(x, root);
}

template <typename Comparable>
AvlTree<Comparable>& AvlTree<Comparable>::operator=(const AvlTree &rhs) {
    root = clone(rhs.root);
}

template <typename Comparable>
AvlTree<Comparable>& AvlTree<Comparable>::operator=(AvlTree &&lhs) {
    root = lhs.root;
    lhs.root = nullptr;
}

template <typename Comparable>
void AvlTree<Comparable>::insert(const Comparable &x, AvlNode * &t) {
    if (t == nullptr)
        t = new AvlNode(x, nullptr, nullptr);    // 创建new所以需要传引用调用
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
    else
        return;
    balance(t); // 递归调用balance
}

template <typename Comparable>
void AvlTree<Comparable>::insert(Comparable &&x, AvlNode * &t) {
    if (t == nullptr)
        t = new AvlNode(std::move(x), nullptr, nullptr);
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (t->element < x)
        insert(std::move(x), t->right);
    else
        return;
    balance(t);
}

template <typename Comparable>
void AvlTree<Comparable>::remove(const Comparable &x, AvlNode * &t) {
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
        AvlNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
    balance(t);
}

template <typename Comparable>
void AvlTree<Comparable>::balance(AvlNode * &t) {
    if (t == nullptr)
        return;
    if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
        if (height(t->left->left) >= height(t->left->right))
            rotateWithLeftChild(t);
        else
            doubleWithLeftChild(t);
    else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
        if (height(t->right->right) >= height(t->right->left))
            rotateWithRightChild(t);
        else
            doubleWithRightChild(t);
    t->height = max(height(t->left), height(t->right)) + 1;
}

template <typename Comparable>
void AvlTree<Comparable>::rotateWithLeftChild(AvlNode * &k2) {
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template <typename Comparable>
void AvlTree<Comparable>::rotateWithRightChild(AvlNode * &k1) {
    AvlNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(k1->height, height(k2->right)) + 1;
    k1 = k2;
}

template <typename Comparable>
void AvlTree<Comparable>::doubleWithLeftChild(AvlNode * &k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template <typename Comparable>
void AvlTree<Comparable>::doubleWithRightChild(AvlNode * &k3) {
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::findMin(AvlNode *t) const {
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::findMax(AvlNode *t) const {
    if (t == nullptr)
        return nullptr;
    if (t->right == nullptr)
        return t;
    return findMax(t->right);
}

template <typename Comparable>
bool AvlTree<Comparable>::contains(const Comparable &x, AvlNode *t) const {
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
void AvlTree<Comparable>::makeEmpty(AvlNode * &t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

template <typename Comparable>
void AvlTree<Comparable>::printTree(ostream &out, AvlNode *t, int depth) const {
    if (t == nullptr)
        return;
    else if (t->left == nullptr && t->right == nullptr) {
        for (int i = 0; i < depth; i++)
            out << ' ';
        out << t->element << endl;
    }
    else {
        for (int i = 0; i < depth; i++)
            out << ' ';
        out << t->element << endl;
        printTree(out, t->left, depth + 1);
        printTree(out, t->right, depth + 1);
    }        
}

template <typename Comparable>
typename AvlTree<Comparable>::AvlNode *AvlTree<Comparable>::clone(AvlNode *t) const {
    if (t == nullptr)
        return nullptr;
    else
        return new AvlNode(t->element, clone(t->left), clone(t->right));
}

#endif