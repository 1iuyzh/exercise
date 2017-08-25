#include<iostream>
#include<string>

using std::cin; using std::cout; using std::endl;
using std::string;

// 类指针
class TreeNode {
public:
    TreeNode() : value(string()), count(new int(1)), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode &rhs) : 
                value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {
                    ++*count;
                }
    TreeNode& operator=(const TreeNode &rhs) {
        ++*rhs.count;
        if (--*count == 0) {
            delete left;
            delete right;
            delete count;
        }
        value = rhs.value;
        left = rhs.left;
        right = rhs.right;
        count = rhs.count;
        return *this;
    }
    ~TreeNode() {
        if (--*count == 0) {
            delete left;
            delete right;
            delete count;
        }
    }
private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};