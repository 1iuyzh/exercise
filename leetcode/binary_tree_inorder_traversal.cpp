/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [1,3,2]

Follow up: Recursive solution is trivial, could you do it iteratively?
*/

#include<vector>
#include<stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<pair<TreeNode *, bool>> s;
        s.emplace(root, false);

        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            if (p.first == nullptr)
                continue;
            if (p.second)
                res.push_back(p.first->val);
            else {
                s.emplace(p.first->right, false);
                s.emplace(p.first, true);
                s.emplace(p.first->left, false);
            }
        }
        return res;
    }
};