/*
Problem Statement: https://leetcode.com/problems/merge-k-sorted-lists/
Time: O(n • log k)
Space: O(n • k + k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *head, *curr;
		head = curr = nullptr;
		
		// helper function
		auto compare = [](ListNode* l1, ListNode* l2) {
			if (!l1)
				return static_cast<bool>(l2);
			else if (!l2)
				return static_cast<bool>(l2);
			else
				return l1->val > l2->val;
		};
		priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
		
		// initialization
		for (ListNode* list: lists)
			if (list)
				pq.push(list);
		
		// merge the k sorted lists
		while (!pq.empty()) {
			ListNode* list = pq.top();
			pq.pop();
			
			if (!head)
				head = list;
			
			if (curr)
				curr->next = list;
			curr = exchange(list, list->next);
			curr->next = nullptr;
			
			if (list)
				pq.push(list);
		}
		
		return head;
	}
};