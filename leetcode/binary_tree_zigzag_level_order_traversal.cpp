/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[[3], [20,9], [15,7]]
*/

#include <vector>
#include <deque>
using std::vector;
using std::deque;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        TreeNode* node = root;
        deque<TreeNode *> de;
        de.emplace_front(root);
        int cnt = 1;
        int cnt_next = 0;
        int lr = 0; //0: left->right, 1: left<-right
        vector<int> temp;
        while (de.size() > 0) {
            temp.clear();
            while (cnt) {
                if (lr == 0) {
                    if (de.front()->left) {
                        de.push_back(de.front()->left);
                        ++cnt_next;
                    }
                    if (de.front()->right) {
                        de.push_back(de.front()->right);
                        ++cnt_next;
                    }
                    temp.push_back(de.front()->val);
                    de.pop_front();
                }
                else {
                    if (de.back()->right) {
                        de.push_front(de.back()->right);
                        ++cnt_next;
                    }
                    if (de.back()->left) {
                        de.push_front(de.back()->left);
                        ++cnt_next;
                    }
                    temp.push_back(de.back()->val);
                    de.pop_back();
                }
                --cnt;
            }
            res.push_back(temp);
            lr = lr == 0 ? 1 : 0;
            cnt = cnt_next;
            cnt_next = 0;
        }
        return res;
    }
};