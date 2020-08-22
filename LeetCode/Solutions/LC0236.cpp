/*
Problem Statement: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
		if (node == p || node == q || !node)
			return node;
		
		TreeNode *left, *right;
		left = lowestCommonAncestor(node->left, p, q);
		right = lowestCommonAncestor(node->right, p, q);
		
		if (left && right)
			return node;
		else if (left)
			return left;
		else
			return right;
	}
};