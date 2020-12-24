/*
Problem Statement: https://leetcode.com/problems/univalued-binary-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		if (!root)
			return true;
		else
			return is_univalued(root, root->val);
	}
	
	bool is_univalued(TreeNode* node, int val) {
		if (!node)
			return true;
		else
			return (node->val == val) && is_univalued(node->left, val) && is_univalued(node->right, val);
	}
};