/*
Problem Statement: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
*/

class Solution {
public:
	int longestZigZag(TreeNode* root) {
		return zigzag(root)[2];
	}
	
	vector<int> zigzag(TreeNode* node) {
		if(!node)
			return {-1, -1, -1};
		vector<int> l, r;
		l = zigzag(node->left);
		r = zigzag(node->right);
		int h = max(1 + max(l[1], r[0]), max(l[2], r[2]));
		return {1 + l[1], 1 + r[0], h};
	}
};