/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5

Example 2:
Input: 1->1->1->2->3
Output: 2->3
*/

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return head;
        ListNode Node(head->val-1);
        Node.next = head;
        ListNode *old = &Node;
        ListNode *ptr = old->next;
        while (ptr != nullptr) {
            while (ptr != nullptr && ptr->val == old->next->val)
                ptr = ptr->next;
            if (ptr != old->next->next)
                old->next = ptr;
            else
                old = old->next;
        }
        return Node.next;
    }
}