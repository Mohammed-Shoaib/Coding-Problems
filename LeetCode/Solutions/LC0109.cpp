/*
Problem Statement: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	int length(ListNode* head) {
		int len = 0;
		while (head) {
			len++;
			head = head->next;
		}
		return len;
	}
	
	TreeNode* build(int low, int high, ListNode*& head) {
		// base case
		if (low > high)
			return nullptr;
		
		TreeNode *left, *right;
		int mid = low + (high - low) / 2;
		
		left = build(low, mid - 1, head);
		int val = head->val;
		head = head->next;
		right = build(mid + 1, high, head);
		
		return new TreeNode(val, left, right);
	}
	
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return build(0, length(head) - 1, head);
	}
};