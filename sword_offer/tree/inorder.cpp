/*
 * 中序遍历二叉树
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
void InorderTraversal1(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr)
        return;
    
    std::stack<BinaryTreeNode *> stackTreeNode;
    stackTreeNode.push(pRoot);
    BinaryTreeNode* pNode;

    while (!stackTreeNode.empty()) {
        pNode = stackTreeNode.top();
        while (pNode->pLeft != nullptr) {
            stackTreeNode.push(pNode->pLeft);
            pNode = pNode->pLeft;
        }
        while (pNode->pRight == nullptr && !stackTreeNode.empty()) {
            std::cout << pNode->value << ' ';
            stackTreeNode.pop();
            if (!stackTreeNode.empty())
                pNode = stackTreeNode.top(); //作用在两处情况
        }
        if (!stackTreeNode.empty()) {
            std::cout << pNode->value << ' ';
            stackTreeNode.pop();
            stackTreeNode.push(pNode->pRight);
        }
    }
}

//递归版本
void InorderTraversal2(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr)
        return;
    InorderTraversal2(pRoot->pLeft);
    std::cout << pRoot->value << ' ';
    InorderTraversal2(pRoot->pRight);
}

//测试
int main() {
    BinaryTreeNode* pRoot = new BinaryTreeNode(4);
    pRoot->pLeft = new BinaryTreeNode(2);
    pRoot->pLeft->pRight = new BinaryTreeNode(3);
    pRoot->pRight = new BinaryTreeNode(7);
    pRoot->pRight->pLeft = new BinaryTreeNode(5);

    InorderTraversal1(pRoot);
    std::cout << std::endl;
    InorderTraversal2(pRoot);
    return 0;
}