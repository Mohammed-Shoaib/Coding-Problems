/*
Problem Statement: https://leetcode.com/problems/subtree-of-another-tree/
*/

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!s)
			return false;
		else
			return same(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}

	bool same(TreeNode* s, TreeNode* t) {
		if (!s && !t)
			return true;
		else if (!s || !t || s->val != t->val)
			return false;
		else
			return same(s->left, t->left) && same(s->right, t->right);
	}
};