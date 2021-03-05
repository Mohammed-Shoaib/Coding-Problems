/*
Problem Statement: https://leetcode.com/problems/average-of-levels-in-binary-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		queue<TreeNode*> q;
		vector<double> averages;
		
		if (root)
			q.push(root);
		
		while (!q.empty()) {
			double sum = 0;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				root = q.front();
				q.pop();
				sum += root->val;
				if (root->left)
					q.push(root->left);
				if (root->right)
					q.push(root->right);
			}
			averages.push_back(sum / size);
		}
		
		return averages;
	}
};