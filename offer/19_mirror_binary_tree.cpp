struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void MirrorRecursively (BinaryTreeNode* pNode) {
    if (pNode == nullptr || (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr))
        return;
    
    BinaryTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if (pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);
    
    if (pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}