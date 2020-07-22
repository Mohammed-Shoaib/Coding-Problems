/*
Problem Statement: https://leetcode.com/problems/remove-linked-list-elements/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *prev, *curr, *next;
		prev = nullptr;
		curr = head;

		while (curr) {
			next = curr->next;
			if (curr->val == val) {
				if (prev)
					prev->next = next;
				else
					head = next;
				delete curr;
				curr = prev;
			}
			prev = exchange(curr, next);
		}

		return head;
	}
};