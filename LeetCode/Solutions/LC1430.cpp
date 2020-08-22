/*
Problem Statement: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/
Time: O(n)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isValidSequence(TreeNode* root, vector<int>& arr) {
		return isValidSequence(0, root, arr);
	}
	
	bool is_leaf(TreeNode* root) {
		return root && !root->left && !root->right;
	}
	
	bool isValidSequence(int ptr, TreeNode* root, vector<int>& arr) {
		if (!root || ptr == arr.size() || root->val != arr[ptr])
			return false;
		else if (ptr + 1 == arr.size())
			return is_leaf(root);
		else
			return isValidSequence(ptr + 1, root->left, arr) || isValidSequence(ptr + 1, root->right, arr);
	}
};