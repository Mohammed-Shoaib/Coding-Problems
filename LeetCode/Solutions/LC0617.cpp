/*
Problem Statement: https://leetcode.com/problems/merge-two-binary-trees/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		int sum = 0;
		pair<TreeNode*, TreeNode*> left, right;
		
		if (!t1 && !t2)
			return nullptr;
		
		if (t1) {
			sum += t1->val;
			left.first = t1->left;
			right.first = t1->right;
		}
		
		if (t2) {
			sum += t2->val;
			left.second = t2->left;
			right.second = t2->right;
		}
		
		return new TreeNode(sum, mergeTrees(left.first, left.second), mergeTrees(right.first, right.second));
	}
};