/*
Problem Statement: https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> order;
		stack<TreeNode*> st;
		if (root)
			st.push(root);
		while (!st.empty()) {
			root = st.top();
			st.pop();
			order.push_back(root->val);
			if (root->right)
				st.push(root->right);
			if (root->left)
				st.push(root->left);
		}
		return order;
    }
};