/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input:
    2
   / \
  1   3
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
*/

#include<stack>
#include<climits>
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return (valid(root, LONG_MIN, LONG_MAX));
    }
    bool valid(TreeNode *node, long min, long max) {
        if (!node)
            return true;
        if (node->val <= min || node->val >= max)
            return false;
        return (valid(node->left, min, node->val) && valid(node->right, node->val, max));
    }
};