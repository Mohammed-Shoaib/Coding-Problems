/*
Problem Statement: https://leetcode.com/problems/middle-of-the-linked-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode *slow, *fast;
		slow = fast = head;

		// floyd's cycle-finding algorithm
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		return slow;
	}
};