/*
Problem Statement: https://leetcode.com/problems/binary-tree-postorder-traversal/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> order;
		stack<TreeNode*> st;
		
		while (!st.empty() || root) {
			while (root) {
				if (root->right)
					st.push(root->right);
				st.push(root);
				root = root->left;
			}
			
			root = st.top();
			st.pop();
			
			if (!st.empty() && root->right == st.top()) {
				st.pop();
				st.push(root);
				root = root->right;
			} else {
				order.push_back(root->val);
				root = nullptr;
			}
		}
		
		return order;
	}
};