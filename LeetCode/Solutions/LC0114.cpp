/*
Problem Statement: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void flatten(TreeNode* root) {
		while (root) {
			TreeNode* node = root->left;
			if (node) {
				while (node->right)
					node = node->right;
				node->right = root->right;
				root->right = exchange(root->left, nullptr);
			}
			root = root->right;
		}
	}
};