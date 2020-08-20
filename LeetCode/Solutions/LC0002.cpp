/*
Problem Statement: https://leetcode.com/problems/add-two-numbers/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode *head, *l;
		head = l = new ListNode(0);
		
		// add the lists
		while (l1 || l2 || carry) {
			if (l1) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				carry += l2->val;
				l2 = l2->next;
			}
			l->next = new ListNode(carry % 10);
			l = l->next;
			carry /= 10;
		}
		
		// clean-up
		l = exchange(head, head->next);
		delete l;
		
		return head;
	}
};