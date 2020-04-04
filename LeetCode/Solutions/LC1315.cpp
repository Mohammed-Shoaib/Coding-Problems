/*
Problem Statement: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
*/

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
		return DFS(root, 1, 1);
    }

	int DFS(TreeNode* node, int pval, int gpval) {
		int sum = 0;
		if (gpval % 2 == 0)
			sum += node->val;
		if (node->left)
			sum += DFS(node->left, node->val, pval);
		if (node->right)
			sum += DFS(node->right, node->val, pval);
		return sum;
	}
};