/*
Problem Statement: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
Time: O(n log³ n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		map<int, map<int, set<int>, greater<int>>> mp;
		
		function<void(int, int, TreeNode*)> dfs = [&](int x, int y, TreeNode* root) {
			if (!root)
				return;
			mp[x][y].insert(root->val);
			dfs(x - 1, y - 1, root->left);
			dfs(x + 1, y - 1, root->right);
		};
		dfs(0, 0, root);
		
		vector<vector<int>> order;
		for (auto& [x, m]: mp) {
			order.push_back(vector<int>());
			for (auto& [y, v]: m)
				order.back().insert(order.back().end(), v.begin(), v.end());
		}
		
		return order;
	}
};