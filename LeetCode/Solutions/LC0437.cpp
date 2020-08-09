/*
Problem Statement: https://leetcode.com/problems/path-sum-iii/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		unordered_map<int, int> freq;
		freq[0]++;
		return dfs(0, sum, root, freq);
	}

	int dfs(int sum, int target, TreeNode* node, unordered_map<int, int>& freq) {
		if (!node)
			return 0;
		
		sum += node->val;
		int cnt = freq[sum - target];
		freq[sum]++;

		cnt += dfs(sum, target, node->left , freq);
		cnt += dfs(sum, target, node->right, freq);
		freq[sum]--;

		return cnt;
	}
};