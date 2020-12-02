/*
Problem Statement: https://leetcode.com/problems/reverse-linked-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *next, *prev = nullptr;
		while (head) {
			next = head->next;
			head->next = prev;
			prev = exchange(head, next);
		}
		return prev;
	}
};