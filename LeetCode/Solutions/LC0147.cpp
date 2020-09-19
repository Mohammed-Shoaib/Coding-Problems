/*
Problem Statement: https://leetcode.com/problems/insertion-sort-list/
*/

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head)
			return nullptr;
		
		ListNode *prev, *node;
		prev = head;
		node = head->next;

		while (node) {
			if (prev->val <= node->val) {
				prev = node;
				node = node->next;
				continue;
			}
			ListNode* prev_s, *next_s;
			prev_s = nullptr;
			next_s = head;
			while (next_s && next_s->val < node->val) {
				prev_s = next_s;
				next_s = next_s->next;
			}
			prev->next = node->next;
			node->next = next_s;
			if (prev_s)
				prev_s->next = node;
			else
				head = node;
			node = prev->next;
		}

		return head;
	}
};