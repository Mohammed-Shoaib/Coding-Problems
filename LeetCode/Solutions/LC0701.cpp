/*
Problem Statement: https://leetcode.com/problems/insert-into-a-binary-search-tree/
Time: O(h)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (!root)
			return new TreeNode(val);
		else if (val < root->val)
			root->left = insertIntoBST(root->left, val);
		else
			root->right = insertIntoBST(root->right, val);
		return root;
	}
};