/*
Problem Statement: https://leetcode.com/problems/binary-tree-tilt/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findTilt(TreeNode* root) {
		int sum = 0;
		
		function<int(TreeNode*)> dfs = [&](TreeNode* node) {
			if (!node)
				return 0;
			int left = dfs(node->left), right = dfs(node->right);
			sum += abs(left - right);
			return node->val + left + right;	
		};
		dfs(root);
		
		return sum;
	}
};