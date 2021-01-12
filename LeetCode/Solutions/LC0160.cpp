/*
Problem Statement: https://leetcode.com/problems/intersection-of-two-linked-lists/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *nodeA = headA, *nodeB = headB;
		
		while (nodeA != nodeB) {
			nodeA = nodeA ? nodeA->next : headB;
			nodeB = nodeB ? nodeB->next : headA;
		}
		
		return nodeA;
	}
};