/*
Problem Statement: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/

class Solution {
public:
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> b1, b2, b3;
		inorder(root1, b1);
		inorder(root2, b2);
		merge(b1, b2, b3);
		return b3;
	}
	
	void inorder(TreeNode* node, vector<int>& b) {
		if (!node)
			return;
		inorder(node->left, b);
		b.push_back(node->val);
		inorder(node->right, b);
	}
	
	void merge(vector<int>& b1, vector<int>& b2, vector<int>& b3) {
		int i, j;
		i = j = 0;
		while (i < b1.size() && j < b2.size()) {
			if (b1[i] < b2[j])
				b3.push_back(b1[i++]);
			else
				b3.push_back(b2[j++]);
		}
		while (i < b1.size())
			b3.push_back(b1[i++]);
		while (j < b2.size())
			b3.push_back(b2[j++]);
	}
};