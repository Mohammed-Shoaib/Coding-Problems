/*
Problem Statement: https://leetcode.com/problems/symmetric-tree/
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		return isSymmetric(root, root);
    }
	
	bool isSymmetric(TreeNode* node1, TreeNode* node2) {
		if (!node1 || !node2)
			return (!node1 && !node2);
		else
			return (node1->val == node2->val) && isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
	}
};