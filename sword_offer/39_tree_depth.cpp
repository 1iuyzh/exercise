/*
 * 二叉树的深度
 * 判断平衡二叉树
 */

struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

int TreeDepth(BinaryTreeNode* pRoot) {
    if (pRoot == nullptr)
        return 0;
    
    int nLeft = TreeDepth(pRoot->m_pLeft);
    int nRight = TreeDepth(pRoot->m_pRight);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

bool isBalanced(BinaryTreeNode* pRoot, int* pDepth) {
    if (pRoot == nullptr) {
        *pDepth = 0;
        return true;
    }

    int left, right;
    if (isBalanced(pRoot->m_pLeft, &left) && isBalanced(pRoot->m_pRight, &right)) {
        int diff = left - right;
        if (diff <= 1 && diff >= -1) {
            *pDepth = 1 + (left > right) ? left : right;
            return true;
        }
    }
    return false;
}