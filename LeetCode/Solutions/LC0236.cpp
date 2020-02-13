/*
Problem Statement: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        TreeNode *left, *right;
        if (node == p || node == q || !node)
            return node;
        left = lowestCommonAncestor(node->left, p, q);
        right = lowestCommonAncestor(node->right, p, q);
        if (left && right)
            return node;
        else if (left)
            return left;
        else
            return right;
    }
};