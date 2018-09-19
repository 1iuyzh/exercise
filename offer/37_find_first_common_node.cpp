/*
 * 两个链表的第一个公共结点
 * O(m+n)
 */

struct ListNode {
    int m_nKey;
    ListNode* m_pNext;
};

unsigned int GetListLength(ListNode*);

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
    unsigned int nLength1 = GetListLength(pHead1);
    unsigned int nLength2 = GetListLength(pHead2);
    
    ListNode* pNode1 = pHead1;
    ListNode* pNode2 = pHead2;

    if (nLength1 > nLength2) {
        for (int i = 0; i < nLength1 - nLength2; ++i)
            pNode1 = pNode1->m_pNext;
    }
    else if (nLength1 < nLength2) {
        for (int i = 0; i < nLength2 - nLength1; ++i)
            pNode2 = pNode2->m_pNext;
    }

    while (pNode1 != nullptr && pNode2 != nullptr && pNode1 != pNode2) {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }

    ListNode* pFirstCommonNode = pNode1;
    return pFirstCommonNode;
}

unsigned int GetListLength(ListNode* pHead) {
    unsigned int nLength = 0;
    ListNode* pNode = pHead;
    while (pNode != nullptr) {
        ++nLength;
        pNode = pNode->m_pNext;
    }
    return nLength;
}