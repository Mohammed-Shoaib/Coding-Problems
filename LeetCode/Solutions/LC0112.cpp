/*
Problem Statement: https://leetcode.com/problems/path-sum/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)
			return false;
		sum -= root->val;
		if (!root->left && !root->right)
			return sum == 0;
		else
			return hasPathSum(root->left, sum) | hasPathSum(root->right, sum);
	}
};