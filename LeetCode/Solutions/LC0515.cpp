/*
Problem Statement: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
		int size, max_v;
		vector<int> rows;
		queue<TreeNode*> q;

		if (root)
			q.push(root);

		while (!q.empty()) {
			size = q.size();
			max_v = numeric_limits<int>::min();
			while (size--) {
				root = q.front();
				q.pop();
				max_v = max(root->val, max_v);
				if (root->left)
					q.push(root->left);
				if (root->right)
					q.push(root->right);
			}
			rows.push_back(max_v);
		}

		return rows;
    }
};