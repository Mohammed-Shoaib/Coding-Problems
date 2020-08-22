/*
Problem Statement: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int sumEvenGrandparent(TreeNode* root) {
		return dfs(root, 1, 1);
	}
	
	int dfs(TreeNode* node, int pval, int gpval) {
		int sum = 0;
		if (gpval % 2 == 0)
			sum += node->val;
		if (node->left)
			sum += dfs(node->left, node->val, pval);
		if (node->right)
			sum += dfs(node->right, node->val, pval);
		return sum;
	}
};