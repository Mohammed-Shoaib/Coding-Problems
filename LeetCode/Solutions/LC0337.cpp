/*
Problem Statement: https://leetcode.com/problems/house-robber-iii/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int rob(TreeNode* root) {
		pair<int, int> dp = house_robber(root);
		return max(dp.first, dp.second);
	}
	
	pair<int, int> house_robber(TreeNode* node) {
		if (!node)
			return {};
		pair<int, int> dp, left, right;
		
		left = house_robber(node->left);
		right = house_robber(node->right);
		
		dp.first = node->val + left.second + right.second;
		dp.second = max(left.first, left.second) + max(right.first, right.second);
		
		return dp;
	}
};