/*
Problem Statement: https://leetcode.com/problems/binary-tree-right-side-view/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		int size, level = 0;
		queue<TreeNode*> q;
		vector<int> values;
		
		if (root)
			q.push(root);
			
		while (!q.empty()) {
			size = q.size();
			while (size--) {
				root = q.front();
				q.pop();
				if (level == values.size())
					values.push_back(root->val);
				if (root->right)
					q.push(root->right);
				if (root->left)
					q.push(root->left);
			}
			level++;
		}
		
		return values;     
	}
};