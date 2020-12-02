/*
Problem Statement: https://leetcode.com/problems/linked-list-cycle/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *slow, *fast;
		slow = fast = head;
		
		// floyd's cycle-finding algorithm
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
				return true;
		}
		
		return false;
	}
};