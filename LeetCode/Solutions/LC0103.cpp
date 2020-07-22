/*
Problem Statement: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		bool flip = false;
		queue<TreeNode*> q;
		vector<vector<int>> levels;
		
		if (root)
			q.push(root);
		
		// level-order traversal
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
			if (flip)
				reverse(level.begin(), level.end());
			levels.push_back(level);
			flip ^= true;
		}
		
		return levels;
	}
};