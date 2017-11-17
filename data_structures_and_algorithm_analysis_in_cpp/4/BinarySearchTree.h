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

    BinaryNode *findMax(BinaryNode *t) const;
    BinaryNode *findMin(BinaryNode *t) const;
    bool contains(const Comparable &x, BinaryNode *t) const;
    
};