/*
Problem Statement: https://leetcode.com/problems/binary-tree-maximum-path-sum/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		return path_sum(root).second;
	}
	
	pair<int, int> path_sum(TreeNode* node) {
		// [sum going up, sum through middle]
		pair<int, int> left, right, sum;
		
		if (!node)
			return {0, numeric_limits<int>::min()};
		
		left = path_sum(node->left);
		right = path_sum(node->right);
		
		sum.first = max(0, node->val + max(left.first, right.first));
		sum.second = max({left.second, right.second, left.first + node->val + right.first});
		
		return sum;
	}
};