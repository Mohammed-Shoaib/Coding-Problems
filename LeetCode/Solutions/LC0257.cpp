/*
Problem Statement: https://leetcode.com/problems/binary-tree-paths/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<int> path;
		vector<string> paths;
		
		function<void(TreeNode*)> dfs = [&](TreeNode* node) {
			if (!node)
				return;
			path.push_back(node->val);
			
			if (!node->left && !node->right) {
				string s;
				for (int i = 0; i + 1 < path.size(); i++)
					s += to_string(path[i]) + "->";
				s += to_string(path.back());
				paths.push_back(s);
			}
			
			dfs(node->left);
			dfs(node->right);
			path.pop_back();
		};
		dfs(root);
		
		return paths;
	}
};