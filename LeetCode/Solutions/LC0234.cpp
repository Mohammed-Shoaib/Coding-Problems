/*
Problem Statement: https://leetcode.com/problems/palindrome-linked-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode *tail, *beg, *mid, *end;
		beg = head;
		mid = middle_node(head);
		tail = end = reverse_list(mid);

		while (beg != mid) {
			if (beg->val != end->val) {
				reverse_list(tail);
				return false;
			}
			beg = beg->next;
			end = end->next;
		}
		reverse_list(tail);

		return true;
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