/*
Problem Statement: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* swapNodes(ListNode* head, int k) {
		ListNode *prev1, *node1, *prev2, *node2, *temp = head;
		prev1 = prev2 = node1 = node2 = nullptr;
					
		// find the nodes to swap and their previous nodes
		while (temp) {
			k--;
			if (k >= 0) {
				prev1 = exchange(node1, temp);
				node2 = head, prev2 = nullptr;
			}
			if (temp->next)
				prev2 = exchange(node2, node2->next);
			temp = temp->next;
		}
		
		// re-wire the nodes and perform the actual swapping
		if (prev1)
			prev1->next = node2;
		else
			head = node2;
		if (prev2)
			prev2->next = node1;
		else
			head = node1;
		node1->next = exchange(node2->next, node1->next);
		
		return head;
	}
};