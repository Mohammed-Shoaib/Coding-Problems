/*
Problem Statement: https://leetcode.com/problems/binary-tree-pruning/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* pruneTree(TreeNode* root) {
		if (!root)
			return nullptr;
		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);
		if (root->val || root->left || root->right)
			return root;
		else
			return nullptr;
	}
};