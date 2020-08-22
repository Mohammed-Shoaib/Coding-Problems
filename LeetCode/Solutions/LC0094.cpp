/*
Problem Statement: https://leetcode.com/problems/binary-tree-inorder-traversal/
Time: O(n)
Space: O(n + h)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> order;
		stack<TreeNode*> st;
		
		while (root || !st.empty()) {
			while (root) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			order.push_back(root->val);
			root = root->right;
		}
		
		return order;
	}
};