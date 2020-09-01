/*
Problem Statement: https://leetcode.com/problems/delete-node-in-a-bst/
Time: O(h)
Space: O(h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return nullptr;
		else if (key != root->val) {
			if (key < root->val)
				root->left = deleteNode(root->left, key);
			else
				root->right = deleteNode(root->right, key);
			return root;
		}
		
		TreeNode *prev = nullptr, *succ = root->right;
		
		while (succ && succ->left)
			prev = exchange(succ, succ->left);
		
		if (succ)
			succ->left = root->left;
		else
			succ = root->left;
		if (prev)
			prev->left = exchange(succ->right, root->right);
		delete root;
		
		return succ;
	}
};