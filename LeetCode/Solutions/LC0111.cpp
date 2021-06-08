/*
Problem Statement: https://leetcode.com/problems/minimum-depth-of-binary-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		else
			return depth(root);
	}
	
	int depth(TreeNode* node) {
		if (!node)
			return numeric_limits<int>::max();
		else if (!node->left && !node->right)
			return 1;
		int left = depth(node->left), right = depth(node->right);
		return 1 + min(left, right);
	}
};