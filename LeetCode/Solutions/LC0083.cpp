/*
Problem Statement: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *node, *temp;
		node = temp = head;
		
		if (temp)
			temp = temp->next;
		
		while (temp) {
			if (node->val == temp->val)
				node->next = temp->next;
			else
				node = temp;
			temp = temp->next;
		}
		
		return head;
	}
};