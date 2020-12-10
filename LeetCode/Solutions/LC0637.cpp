/*
Problem Statement: https://leetcode.com/problems/average-of-levels-in-binary-tree/
*/

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		int size;
		double sum;
		queue<TreeNode*> q;
		vector<double> averages;

		if (root)
			q.push(root);
		
		while (!q.empty()) {
			sum = 0;
			size = q.size();
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