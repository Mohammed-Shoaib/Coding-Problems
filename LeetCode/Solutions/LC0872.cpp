/*
Problem Statement: https://leetcode.com/problems/leaf-similar-trees/
Time: O(m + n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		stack<TreeNode*> st1, st2;
		
		if (root1)
			st1.push(root1);
		if (root2)
			st2.push(root2);
		
		while (!st1.empty() && !st2.empty())
			if (get_leaf(st1) != get_leaf(st2))
				return false;
		
		return st1.empty() && st2.empty();
	}
	
	int get_leaf(stack<TreeNode*>& st) {
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			if (!node->left && !node->right)
				return node->val;
			if (node->right)
				st.push(node->right);
			if (node->left)
				st.push(node->left);
		}
		return -1;
	}
};