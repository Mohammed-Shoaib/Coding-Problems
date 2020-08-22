/*
Problem Statement: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Time: O(h)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		while (root) {
			if (max(p->val, q->val) < root->val)
				root = root->left;
			else if (min(p->val, q->val) > root->val)
				root = root->right;
			else
				return root;
		}
		return nullptr;
	}
};