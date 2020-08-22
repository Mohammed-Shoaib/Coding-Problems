/*
Problem Statement: https://leetcode.com/problems/validate-binary-search-tree/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return is_valid(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());	
	}
	
	bool is_valid(TreeNode* node, long long min, long long max) {
		if (!node)
			return true;
		else if (min >= node->val || max <= node->val)
			return false;
		else
			return is_valid(node->left, min, node->val) && is_valid(node->right, node->val, max);
	}
};