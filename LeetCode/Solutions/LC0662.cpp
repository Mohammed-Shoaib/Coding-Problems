/*
Problem Statement: https://leetcode.com/problems/maximum-width-of-binary-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int widthOfBinaryTree(TreeNode* root) {
		int max_w = 0;
		queue<pair<TreeNode*, int>> q;
		
		if (root)
			q.push({root, 0});
		
		while (!q.empty()) {
			int size, beg, end, idx;
			size = q.size();
			beg = q.front().second;
			end = q.back().second;
			max_w = max(end - beg + 1, max_w);

			while (size--) {
				tie(root, idx) = q.front();
				q.pop();
				idx -= beg;
				if (root->left)
					q.push({root->left, 2 * idx + 1});
				if (root->right)
					q.push({root->right, 2 * idx + 2});
			}
		}

		return max_w;
	}
};