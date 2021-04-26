/*
Problem Statement: https://leetcode.com/problems/partition-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *head1 = new ListNode(0), *head2 = new ListNode(0);
		ListNode *l1 = head1, *l2 = head2, *node = head;
		
		while (node) {
			ListNode*& l = (node->val < x) ? l1 : l2;
			l = l->next = exchange(node, node->next);
		}
		
		l2->next = nullptr;
		l1->next = head2->next;
		l1 = head1->next;
		delete head1;
		delete head2;
		
		return l1;
	}
};