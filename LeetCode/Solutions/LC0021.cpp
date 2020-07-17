/*
Problem Statement: https://leetcode.com/problems/merge-two-sorted-lists/
Time: O(m + n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *dummy, *l;
		dummy = new ListNode(0);
		l = dummy;

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
		l = dummy->next;
		delete dummy;
		
		return l;
	}
};