/*
Problem Statement: https://leetcode.com/problems/cousins-in-binary-tree
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		pair<TreeNode*, int> node_x, node_y;
		node_x = search(root, x);
		node_y = search(root, y);
		return node_x.first != node_y.first && node_x.second == node_y.second;
	}
	
	pair<TreeNode*, int> search(TreeNode* node, int target, TreeNode* parent = nullptr, int depth = 0) {
		if (!node)
			return {nullptr, 0};
		else if (node->val == target)
			return {parent, depth};
		
		pair<TreeNode*, int> left, right;
		left = search(node->left, target, node, depth + 1);
		right = search(node->right, target, node, depth + 1);
		
		return (left.first) ? left : right;
	}
};