/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr)
            return nullptr;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *root = new ListNode((l1->val + l2->val) % 10);
        ListNode *ptr = root;
        int tmp = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr || tmp != 0) {
            if (l1 == nullptr && l2 == nullptr && tmp != 0) {
                ptr->next = new ListNode(tmp);
                tmp = 0;
                ptr = ptr->next;
            }else if (l1 != nullptr && l2 == nullptr) {
                ptr->next = new ListNode((l1->val + tmp) % 10);
                tmp = (l1->val + tmp) / 10;
                ptr = ptr->next;
                l1 = l1->next;
            } else if (l1 == nullptr && l2 != nullptr) {
                ptr->next = new ListNode((l2->val + tmp) % 10);
                tmp = (l2->val + tmp) / 10;
                ptr = ptr->next;
                l2 = l2->next;
            } else if (l1 != nullptr && l2 != nullptr) {
                ptr->next = new ListNode((l1->val + l2->val + tmp) % 10);
                tmp = (l1->val + l2->val + tmp) / 10;
                ptr = ptr->next;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        return root;
    }
};