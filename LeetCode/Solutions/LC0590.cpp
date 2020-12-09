/*
Problem Statement: https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> order;
		stack<Node*> st;
		
		if (root)
			st.push(root);
		
		while (!st.empty()) {
			root = st.top();
			st.pop();
			order.push_back(root->val);
			for (Node* child: root->children)
				st.push(child);
		}

		reverse(order.begin(), order.end());
		return order;
	}
};