/*
Problem Statement: https://leetcode.com/problems/path-sum-ii/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		int sum = 0;
		vector<int> path;
		vector<vector<int>> paths;
		
		// helper function to dfs
		function<void(TreeNode*)> helper = [&](TreeNode* node) {
			if (!node)
				return;
			
			sum += node->val;
			path.push_back(node->val);
			
			if (sum == targetSum && !node->left && !node->right)
				paths.push_back(path);
			helper(node->left);
			helper(node->right);
			
			sum -= node->val;
			path.pop_back();
		};
		helper(root);
		
		return paths;
	}
};