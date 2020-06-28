/*
Problem Statement: https://leetcode.com/problems/sum-root-to-leaf-numbers/
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
	int sumNumbers(TreeNode* root, int sum = 0) {
		if (!root)
			return 0;
		sum = sum * 10 + root->val;
		if (!root->left && !root->right)
			return sum;
		else
			return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
	}
};