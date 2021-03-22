/*
Problem Statement: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	Node* connect(Node* root) {
		Node* node = root;
		
		if (!root)
			return nullptr;
		
		while (node->left) {
			Node* beg = node;
			while (node) {
				node->left->next = node->right;
				if (node->next)
					node->right->next = node->next->left;
				node = node->next;
			}
			node = beg->left;
		}
		
		return root;
	}
};