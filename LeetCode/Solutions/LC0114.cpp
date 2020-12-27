/*
Problem Statement: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	void flatten(TreeNode* root) {
		flatten(root, nullptr);
	}
	
	TreeNode* flatten(TreeNode* root, TreeNode* prev) {
		if (!root)
			return prev;
		prev = flatten(root->right, prev);
		prev = flatten(root->left, prev);
		root->right = prev;
		root->left = nullptr;
		return root;
	}
};