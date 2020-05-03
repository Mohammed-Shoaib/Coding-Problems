/*
Problem Statement: https://leetcode.com/problems/diameter-of-binary-tree/
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }

    int depth(TreeNode* node, int& diameter) {
        if (!node)
            return 0;
        int left, right;
        left = depth(node->left, diameter);
        right = depth(node->right, diameter);
        diameter = max(left + right, diameter);
        return 1 + max(left, right);
    }
};