#include"BinarySearchTree.h"
#include<iostream>
using namespace std;

template <typename Comparable>
bool BinarySearchTree::contains(const Comparable &x) const {
    return contains(x, root);
}

template <typename Comparable>
bool BinarySearchTree::contains(const Comparable &x, BinaryNode *t) const {
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
const Comparable &BinarySearchTree::findMin() const {
    return findMin(root)->element;
}

template <typename Comparable>
const Comparable &BinarySearchTree::findMax() const {
    return findMax(root)->element;
}

template <typename Comparable>
BinaryNode *BinarySearchTree::findMin(BinaryNode *t) const {
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename Comparable>
BinaryNode *BinarySearchTree::findMax(BinaryNode &t) const {
    if (t == nullptr)
        return nullptr;
    if (t->right == nullptr)
        return t;
    return findMax(t->right);
}

template <typename Comparable>
void BinarySearchTree::insert(const Comparable &x) {
    insert(x, root);
}

template <typename Comparable>
void BinarySearchTree::insert(const Comparable &x, BinaryNode * &t) {
    if (t == nullptr)
        t = new BinaryNode(x, nullptr, nullptr);    // 需要传引用调用指针
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
    else
        return;
}

template <typename Comparable>
void BinarySearchTree::insert(Comparable &&x, BinaryNode * &t) {
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
void BinarySearchTree::remove(const Comparable &x) {
    remove(x, root);
}

template <typename Comparable>
void remove(const Comparable &x, BinaryNode * &t) {
    if (t == nullptr)
        return;
    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t-<right);
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

int main() {
    return 0;
}