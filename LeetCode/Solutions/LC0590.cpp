/*
Problem Statement: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> postorder(Node* root) {
		stack<Node*> st;
		vector<int> order;
		
		if (root)
			st.push(root);
		
		while (!st.empty()) {
			root = st.top();
			st.pop();
			order.push_back(root->val);
			for (Node*& child: root->children)
				st.push(child);
		}
		reverse(order.begin(), order.end());
		
		return order;
	}
};