/*
Problem Statement: https://leetcode.com/problems/binary-tree-right-side-view/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> values;
		
		if (root)
			q.push(root);
		
		// level order traversal
		while (!q.empty()) {
			int size = q.size();
			values.push_back(q.front()->val);
			while (size--) {
				root = q.front();
				q.pop();
				if (root->right)
					q.push(root->right);
				if (root->left)
					q.push(root->left);
			}
		}
		
		return values;     
	}
};