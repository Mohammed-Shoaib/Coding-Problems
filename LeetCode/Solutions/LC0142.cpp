/*
Problem Statement: https://leetcode.com/problems/linked-list-cycle-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow, *fast;
		slow = fast = head;
		
		// floyd's cycle-finding algorithm
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			
			// found cycle
			if (slow == fast) {
				slow = head;
				while (slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		
		return nullptr;
	}
};