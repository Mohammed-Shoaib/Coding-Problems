/*
Problem Statement: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> levels;
		
		if (root)
			q.push(root);
		
		while (!q.empty()) {
			int size = q.size();
			vector<int> level;
			while (size--) {
				root = q.front();
				q.pop();
				level.push_back(root->val);
				if (root->left)
					q.push(root->left);
				if (root->right)
					q.push(root->right);
			}
			levels.push_back(level);
		}
		
		reverse(levels.begin(), levels.end());
		
		return levels;
	}
};