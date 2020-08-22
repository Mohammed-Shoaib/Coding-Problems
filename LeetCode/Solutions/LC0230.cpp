/*
Problem Statement: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int ele;
		stack<TreeNode*> st;
		
		for (int i = 0; i < k; i++) {
			while (root) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			ele = root->val;
			root = root->right;
		}
		
		return ele;
	}
};