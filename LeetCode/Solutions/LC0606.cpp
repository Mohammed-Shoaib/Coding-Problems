/*
Problem Statement: https://leetcode.com/problems/construct-string-from-binary-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	string tree2str(TreeNode* root) {
		string left, right;
		if (!root)
			return "";
		if (root->left || root->right)
			left = "(" + tree2str(root->left) + ")";
		if (root->right)
			right = "(" + tree2str(root->right) + ")";			
		return to_string(root->val) + left + right;
	}
};