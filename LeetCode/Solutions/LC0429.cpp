/*
Problem Statement: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		queue<Node*> q;
		vector<vector<int>> levels;

		if (root)
			q.push(root);

		while (!q.empty()) {
			vector<int> level;
			int size = q.size();
			while (size--) {
				root = q.front();
				q.pop();
				level.push_back(root->val);
				for (Node* child: root->children)
					q.push(child);
			}
			levels.push_back(level);
		}

		return levels;
	}
};