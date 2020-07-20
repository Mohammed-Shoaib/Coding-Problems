/*
Problem Statement: https://leetcode.com/problems/odd-even-linked-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head)
			return nullptr;
		
		ListNode *odd, *even, *even_head;
		odd = head;
		even = even_head = odd->next;

		while (even && even->next) {
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}
		odd->next = even_head;

		return head;
	}
};