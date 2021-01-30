/*
Problem Statement: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
*/

class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int num = 0;
		while (head) {
			num <<= 1;
			num |= head->val;
			head = head->next;
		}
		return num;
	}
};