/*
Problem Statement: https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> order;
		stack<TreeNode*> st;
		
		if (root)
			st.push(root);
		
		while (!st.empty()) {
			root = st.top();
			st.pop();
			order.push_back(root->val);
			if (root->left)
				st.push(root->left);
			if (root->right)
				st.push(root->right);
		}
		
		reverse(order.begin(), order.end());
		return order;
	}
};