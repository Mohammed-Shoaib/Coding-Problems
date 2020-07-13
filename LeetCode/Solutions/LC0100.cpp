/*
Problem Statement: https://leetcode.com/problems/same-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p || !q)
			return !p && !q;
		else
			return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};