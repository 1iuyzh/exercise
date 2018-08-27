/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:
      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

Note:
The size of the given array will be in the range [1,1000].
*/

#include<vector>
#include<algorithm>
using std::vector;
using std::max_element;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode *> nodeStack;
        for (int i = 0; i < nums.size(); i++) {
            auto node = new TreeNode(nums[i]);
            while (!nodeStack.empty() && nums[i] > nodeStack.back()->val) {
                node->left = nodeStack.back();
                nodeStack.pop_back();
            }
            if (!nodeStack.empty()) {
                nodeStack.back()->right = node;
            }
            nodeStack.emplace_back(node);
        }
        return nodeStack.front();
    }
};