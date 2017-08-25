#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

// 类值
class BinStrTree {
public:
    BinStrTree() : root(new TreeNode()) { }
    BinStrTree(const BinStrTree &rhs) : root(new TreeNode(*rhs.root)) { }
    BinStrTree& operator=(const BinStrTree &rhs) {
        TreeNode *newp = new TreeNode(*rhs.root);
        delete root;
        root = newp;
        return *this;
    }
    ~BinStrTree() {
        delete root;
    }
private:
    TreeNode *root;
};