/*
Problem Statement: https://leetcode.com/problems/convert-bst-to-greater-tree/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		convert(0, root);
		return root;
	}
	
	int convert(int sum, TreeNode* node) {
		if (!node)
			return sum;
		node->val += convert(sum, node->right);
		return convert(node->val, node->left);
	}
};