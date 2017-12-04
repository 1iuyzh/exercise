#include"AvlTree.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {
    AvlTree<int> tree;
    vector<int> v{3, 2, 1, 4, 5, 6, 7, 16, 15, 14, 13, 12, 11, 10, 8, 9};
    for (auto i : v)
        tree.insert(i);
    tree.printTree();
    return 0;
}