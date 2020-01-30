/*
Problem Statement: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

class Solution {
public:
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
		bool flip = false;
		queue<TreeNode*> q;
		vector< vector<int> > levels;

		if (root)
			q.push(root);
		
		while (!q.empty()) {
			int pos, size = q.size();
			vector<int> level(size);

			for (int i = 0; i < size; i++) {
				root = q.front();
				q.pop();
				pos = (flip) ? size - i - 1 : i;
				level[pos] = root->val;
				if (root->left)
					q.push(root->left);
				if (root->right)
					q.push(root->right);
			}

			flip = !flip;
			levels.push_back(level);
		}
		
		return levels;
    }
};