/*
Problem Statement: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> preorder(Node* root) {
		stack<Node*> st;
		vector<int> order;
		
		if (root)
			st.push(root);
		
		while (!st.empty()) {
			root = st.top();
			st.pop();
			order.push_back(root->val);
			for (auto it = root->children.rbegin(); it != root->children.rend(); it++)
				st.push(*it);
		}
		
		return order;
	}
};