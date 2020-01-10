/*
Problem Statement: https://leetcode.com/problems/merge-two-sorted-lists/
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *l;
        head = new ListNode(0);
        l = head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                l->next = l1;
                l1 = l1->next;
            } else {
                l->next = l2;
                l2 = l2->next;
            }
            l = l->next;
        }

        l->next = (l1) ? l1 : l2;
        return head->next;
    }
};