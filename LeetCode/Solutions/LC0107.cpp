/*
Problem Statement: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
*/

class Solution {
public:
    vector< vector<int> > levelOrderBottom(TreeNode* root) {
		int size;
		queue<TreeNode*> q;
		vector< vector<int> > levels;

		if (root)
			q.push(root);
		
		while (!q.empty()) {
			size = q.size();
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