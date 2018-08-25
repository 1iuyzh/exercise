/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a 3-ary tree: 
Return its preorder traversal as: [1,3,5,6,2,4].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include<vector>
#include<stack>
using std::vector;
using std::stack;

class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root)
            return res;
        
        stack<Node *> s;
        s.push(root);

        while (!s.empty()) {
            auto pn = s.top();
            s.pop();

            res.push_back(pn->val);
            for (int i = pn->children.size()-1; i >= 0; i--)
                s.push(pn->children[i]);
        }
        return res;
    }
};