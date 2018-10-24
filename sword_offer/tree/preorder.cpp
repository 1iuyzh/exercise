/*
 * 前序遍历二叉树
 */
#include <iostream>
#include <stack>

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* pLeft;
    BinaryTreeNode* pRight;
    BinaryTreeNode() : pLeft(nullptr), pRight(nullptr) {}
    BinaryTreeNode(const int& _value) : value(_value), pLeft(nullptr), pRight(nullptr) {}
};

//循环版本
void PreorderTraversal1(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr)
        return;
    
    std::stack<BinaryTreeNode *> stackTreeNode;
    
    BinaryTreeNode* pNode = pRoot;
    stackTreeNode.push(pNode);

    while (!stackTreeNode.empty()) {
        pNode = stackTreeNode.top();
        std::cout << pNode->value << ' ';
        stackTreeNode.pop();

        if (pNode->pRight != nullptr)
            stackTreeNode.push(pNode->pRight);
        
        if (pNode->pLeft != nullptr)
            stackTreeNode.push(pNode->pLeft);
    }
}

//递归版本
void PreorderTraversal2(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr)
        return;
    
    std::cout << pRoot->value << ' ';
    PreorderTraversal2(pRoot->pLeft);
    PreorderTraversal2(pRoot->pRight);
}

//测试
int main() {
    BinaryTreeNode* pRoot = new BinaryTreeNode(4);
    pRoot->pLeft = new BinaryTreeNode(2);
    pRoot->pLeft->pRight = new BinaryTreeNode(3);
    pRoot->pRight = new BinaryTreeNode(7);
    pRoot->pRight->pLeft = new BinaryTreeNode(5);

    PreorderTraversal1(pRoot);
    std::cout << std::endl;
    PreorderTraversal2(pRoot);
    return 0;
}