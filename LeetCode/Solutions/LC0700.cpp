/*
Problem Statement: https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (!root)
			return nullptr;
		else if (root->val == val)
			return root;
		else if (root->val > val)
			return searchBST(root->left, val);
		else
			return searchBST(root->right, val);
	}
};