/*
Problem Statement: https://leetcode.com/problems/reverse-linked-list-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode *prev, *curr, *next;
		prev = nullptr;
		curr = head;
		n -= m - 1;

		while (--m) {
			prev = curr;
			curr = curr->next;
		}

		ListNode *beg = prev, *end = curr;
		while (n--) {
			next = curr->next;
			curr->next = prev;
			prev = exchange(curr, next);
		}

		if (beg)
			beg->next = prev;
		else
			head = prev;
		end->next = curr;

		return head;
	}
};