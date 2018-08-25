/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

#include<stack>
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) : ptr(root) {}

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty() || ptr != nullptr;
    }

    /** @return the next smallest number */
    int next() {
        while (ptr) {
            s.push(ptr);
            ptr = ptr->left;
        }
        ptr = s.top();
        s.pop();

        auto node = ptr;
        ptr = ptr->right;

        return node->val;
    }
private:
    stack<TreeNode *> s;
    TreeNode *ptr;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */