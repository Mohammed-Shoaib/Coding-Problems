/*
Problem Statement: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *temp, *node, *prev = nullptr;
		temp = node = head;
		
		for (int i = 0, j = 0; temp; i++) {
			if (i >= n)
				prev = exchange(node, node->next);
			temp = temp->next;
		}
		
		if (prev)
			prev->next = node->next;
		else
			head = head->next;
		delete node;
		
		return head;
	}
};