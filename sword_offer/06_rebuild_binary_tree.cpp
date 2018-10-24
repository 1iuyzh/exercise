#include <exception>

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length) {
    if (preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(int* preorderStart, int* preorderEnd, int* inorderStart, int* inorderEnd) {
    int rootValue = preorderStart[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = nullptr;

    if (preorderStart == preorderEnd) {
        if (inorderStart == inorderEnd && *preorderStart == *inorderStart)
            return root;
        else
            throw "Invalid input.";
    }

    int* rootInorder = inorderStart;
    while (rootInorder <= inorderEnd && *rootInorder != rootValue)
        ++rootInorder;
    
    if (rootInorder >= inorderEnd && *rootInorder != rootValue)
        throw "Invalid input.";
    
    int leftLength = rootInorder - inorderStart;
    int* leftPreorderEnd = preorderStart + leftLength;
    if (leftLength > 0)
        root->m_pLeft = ConstructCore(preorderStart + 1, leftPreorderEnd, inorderStart, rootInorder - 1);
    
    if (leftLength < preorderEnd - preorderStart) {
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, preorderEnd, rootInorder + 1, inorderEnd);
    }
}