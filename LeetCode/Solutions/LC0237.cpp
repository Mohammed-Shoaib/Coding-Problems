/*
Problem Statement: https://leetcode.com/problems/delete-node-in-a-linked-list/
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