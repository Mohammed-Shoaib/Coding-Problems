/*
Problem Statement: https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        else
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};