/*
Problem Statement: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int sumRootToLeaf(TreeNode* root, int sum = 0) {
		if (!root)
			return 0;
		sum = (sum << 1) | root->val;
		if (!root->left && !root->right)
			return sum;
		else
			return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
	}
};