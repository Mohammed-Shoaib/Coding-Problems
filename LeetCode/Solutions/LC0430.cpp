/*
Problem Statement: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	Node* flatten(Node* head) {
		stack<Node*> st;
		Node *prev = nullptr, *node = head;

		while (node) {
			prev = node;
			if (!node->child)
				node = node->next;
			else {
				st.push(node->next);
				assign(node, exchange(node->child, nullptr));
			}
			if (!node && !st.empty()) {
				node = st.top();
				st.pop();
				assign(prev, node);
			}
		}

		return head;
	}

	void assign(Node*& node, Node* next) {
		if (next)
			next->prev = node;
		if (node)
			node->next = next;
		node = next;
	};
};