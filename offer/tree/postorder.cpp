/*
 * 后序遍历二叉树
 */

#include <iostream>
#include <stack>
#include <utility>

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode() : pLeft(nullptr), pRight(nullptr) {}
    BinaryTreeNode(const int& _value) : value(_value), pLeft(nullptr), pRight(nullptr) {}
};

void PostorderTraversal1(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr)
        return;
    
    std::stack<std::pair<BinaryTreeNode *, bool>> stackTreeNode;
    stackTreeNode.emplace(pRoot, false);
    std::pair<BinaryTreeNode*, bool> pNode;

    while (!stackTreeNode.empty()) {
        pNode = stackTreeNode.top();
        while (pNode.first->pLeft != nullptr) {
            stackTreeNode.emplace(pNode.first->pLeft, false);
            pNode.first = pNode.first->pLeft;
            pNode.second = false;
        }
        while (pNode.first->pRight == nullptr && !stackTreeNode.empty()) {
            std::cout << pNode.first->value << ' ';
            stackTreeNode.pop();
            if (!stackTreeNode.empty()) {
                pNode = stackTreeNode.top();
                while (pNode.second == true && !stackTreeNode.empty()) {
                    std::cout << pNode.first->value << ' ';
                    stackTreeNode.pop();
                    if (!stackTreeNode.empty())
                        pNode = stackTreeNode.top();
                }
            }
        }
        if (!stackTreeNode.empty()) {
            pNode.second = true;
            stackTreeNode.pop();
            stackTreeNode.push(pNode);
            stackTreeNode.emplace(pNode.first->pRight, false);
        }
    }
}

void PostorderTraversal2(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr)
        return;
    
    PostorderTraversal2(pRoot->pLeft);
    PostorderTraversal2(pRoot->pRight);
    std::cout << pRoot->value << ' ';
}

//测试
int main() {
    BinaryTreeNode* pRoot = new BinaryTreeNode(4);
    pRoot->pLeft = new BinaryTreeNode(2);
    pRoot->pLeft->pRight = new BinaryTreeNode(3);
    pRoot->pRight = new BinaryTreeNode(7);
    pRoot->pRight->pLeft = new BinaryTreeNode(5);

    PostorderTraversal1(pRoot);
    std::cout << std::endl;
    PostorderTraversal2(pRoot);
    return 0;
}