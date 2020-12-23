/*
Problem Statement: https://leetcode.com/problems/range-sum-of-bst/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		int sum = 0;
		if (!root)
			return 0;
		if (L <= root->val && root->val <= R)
			sum += root->val;
		if (L <= root->val)
			sum += rangeSumBST(root->left, L, R);
		if (root->val <= R)
			sum += rangeSumBST(root->right, L, R);
		return sum;
	}
};