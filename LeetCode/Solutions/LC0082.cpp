/*
Problem Statement: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *node, *dummy, *prev;
		node = head;
		dummy = prev = new ListNode(0, head);
		
		while (head) {
			if (node->val != head->val) {
				if (node->next == head)
					prev = exchange(node, head);
				else
					prev->next = node = head;
			}
			head = head->next;
		}
		
		if (node && node->next)
			prev->next = nullptr;
		
		return dummy->next;
	}
};