/*
Problem Statement: https://leetcode.com/problems/sum-of-left-leaves/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root, bool is_left = false) {
		if (!root)
			return 0;
		else if (is_left && !root->left && !root->right)
			return root->val;
		else
			return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
	}
};