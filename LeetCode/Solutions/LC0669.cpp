/*
Problem Statement: https://leetcode.com/problems/trim-a-binary-search-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root)
			return nullptr;
		
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		
		if (root->val < low)
			return root->right;
		else if (root->val > high)
			return root->left;
		else
			return root;
	}
};