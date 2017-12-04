#include"BinarySearchTree.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {
    BinarySearchTree<int> tree;
    vector<int> ivec{3, 1, 5, 0, 4, 2, 6};
    for (auto i : ivec)
        tree.insert(i);
    tree.printTree();
    tree.remove(1);
    tree.printTree();
    return 0;
}