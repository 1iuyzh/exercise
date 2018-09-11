/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [3,2,1]

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using std::vector;
using std::stack;
using std::pair;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;

        std::stack<std::pair<TreeNode *, bool>> stack;
        stack.emplace(root, false);
        std::pair<TreeNode*, bool> node;

        while (!stack.empty()) {
            node = stack.top();
            while (node.first->left != nullptr) {
                stack.emplace(node.first->left, false);
                node.first = node.first->left;
                node.second = false;
            }
            while (node.first->right == nullptr && !stack.empty()) {
                res.push_back(node.first->val);
                stack.pop();
                if (!stack.empty()) {
                    node = stack.top();
                    while (node.second == true && !stack.empty()) {
                        res.push_back(node.first->val);
                        stack.pop();
                        if (!stack.empty())
                            node = stack.top();
                    }
                }
            }
            if (!stack.empty()) {
                node.second = true;
                stack.pop();
                stack.push(node);
                stack.emplace(node.first->right, false);
            }
        }
        return res;
    }
};