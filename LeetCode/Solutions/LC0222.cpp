/*
Problem Statement: https://leetcode.com/problems/count-complete-tree-nodes/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (!root)
			return 0;
		else
			return 1 + countNodes(root->left) + countNodes(root->right);
	}
};