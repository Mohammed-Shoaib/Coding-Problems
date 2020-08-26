/*
Problem Statement: https://leetcode.com/problems/reorder-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode *beg, *mid, *end, *next;
		beg = head;
		mid = middle_node(head);
		end = reverse_list(mid);
		
		// interleave nodes and merge
		while (end && beg != end) {
			beg = exchange(beg->next, end);
			next = (end->next) ? beg : nullptr;
			end = exchange(end->next, next);
		}
	}
	
	ListNode* middle_node(ListNode* head) {
		ListNode *slow, *fast;
		slow = fast = head;
		
		// floyd's cycle-finding algorithm
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		
		return slow;
	}
	
	ListNode* reverse_list(ListNode* head) {
		ListNode *next, *prev = nullptr;
		while (head) {
			next = head->next;
			head->next = prev;
			prev = exchange(head, next);
		}
		return prev;
	}
};