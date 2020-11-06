/*
Problem Statement: https://leetcode.com/problems/balance-a-binary-search-tree/
*/

class Solution {
public:
	TreeNode* balanceBST(TreeNode* root) {
		vector<int> nodes;
		inorder(root, nodes);
		return construct(0, (int) nodes.size() - 1, nodes);
	}

	void inorder(TreeNode* root, vector<int>& nodes) {
		if (!root)
			return;
		inorder(root->left, nodes);
		nodes.push_back(root->val);
		inorder(root->right, nodes);
	}

	TreeNode* construct(int l, int r, vector<int>& nodes) {
		if (l > r)
			return nullptr;
		int mid = (l + r) / 2;
		TreeNode* node = new TreeNode(nodes[mid]);
		node->left = construct(l, mid - 1, nodes);
		node->right = construct(mid + 1, r, nodes);
		return node;
	}
};