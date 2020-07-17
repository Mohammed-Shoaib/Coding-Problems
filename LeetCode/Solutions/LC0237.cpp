/*
Problem Statement: https://leetcode.com/problems/delete-node-in-a-linked-list/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		node->val = next->val;
		node->next = next->next;
		delete next;
	}
};