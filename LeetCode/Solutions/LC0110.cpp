/*
Problem Statement: https://leetcode.com/problems/balanced-binary-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return is_balanced(root) >= 0;
	}
	
	int is_balanced(TreeNode* node) {
		if (!node)
			return 0;
		int left, right;
		left = is_balanced(node->left);
		right = is_balanced(node->right);
		if (left == -1 || right == -1 || abs(left - right) > 1)
			return -1;
		else
			return 1 + max(left, right);
	}
};