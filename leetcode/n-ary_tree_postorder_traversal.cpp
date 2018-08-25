/*
Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:
Return its postorder traversal as: [5,6,3,2,4,1].
 
Note: Recursive solution is trivial, could you do it iteratively?
*/

#include<vector>
#include<stack>
#include<utility>
using std::vector;
using std::stack;
using std::pair;

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
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<pair<Node *, bool>> s;
        s.emplace(root, false);
        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            if (p.second == false) {
                p.second = true;
                s.push(p);
                for (int i = p.first->children.size()-1; i >= 0; i--)
                    s.emplace(p.first->children[i], false);
            }
            else {
                res.push_back(p.first->val);
            }
        }
        return res;
    }
};