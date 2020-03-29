/*
Problem Statement: https://leetcode.com/problems/deepest-leaves-sum/
*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
		int sum, size;
		queue<TreeNode*> q;

		if (root)
			q.push(root);
		
		while (!q.empty()) {
			sum = 0;
			size = q.size();
			while (size--) {
				root = q.front();
				q.pop();
				sum += root->val;
				if (root->left)
					q.push(root->left);
				if (root->right)
					q.push(root->right);
			}
		}

		return sum;
    }
};